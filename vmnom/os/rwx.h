#ifndef RWX_H
#define RWX_H

#include <extends.h>

#define HTTP 80

struct nosql;

struct client {

	int cf;

	sockaddr_in addr;

	string hostname = "{username}$";
};

using connection = map<clock_t, client>;

struct display {

	string buf;

	void clear() {

		cout << "\033[2J\033[H" << flush;

	}

	void console(string line) {

		cout << badge << line << endl;

	}
};

struct network : display {

	int fd;

	int cnt;

	vector<connection> connections;

	void emplace(connection i, clock_t timestamp) {

		if (i.empty()) {

			return;

		}

		client n = i[timestamp];

		char ip[INET_ADDRSTRLEN];

		if (inet_ntop(AF_INET, &n.addr.sin_addr, ip, sizeof(n.addr)) != nullptr)

			n.hostname = string(ip);

		connections.emplace_back(i);

		console(Red(n.hostname + " connected.") );

	}

	connection read() {

		if(connections.empty()) {

			return {};

		}

		connection i = move(connections.back());

		connections.pop_back();

		return i;

	}

	connection mail() {

		client n;

		connection i;

		socklen_t addr_len = sizeof(n.addr);

		int client_socket = accept(
				fd,
				(struct sockaddr *)&n.addr,
				&addr_len
				);

		if (client_socket != -1) {

			i[clock()] = n;
		}

		return i;
	}

	sockaddr_in addr{};

	void publish(int port) {

		fd = socket(AF_INET, SOCK_STREAM, 0);

		if (fd == -1) {

			perror("socket");

			exit(FAILURE);

		}

		addr.sin_family = AF_INET;

		addr.sin_addr.s_addr = INADDR_ANY;

		addr.sin_port = htons(port);

		if (::bind(fd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == -1) {

			perror("bind");

			exit(FAILURE);

		}

		console("binding loopback address.");

		if (listen(fd, SOMAXCONN) == -1) {

			perror("listen");

			exit(EXIT_FAILURE);

		}

		console("listen success.");

	};
};

struct playground : network {

	vector<int, nosql*> w;

	void (*workers) (vector<int, nosql*>*);

	playground& l() {

		workers(&w);

		while(1) {

			emplace(mail(), clock());
			
		}

		return *this;

	}

	playground& plugp(int port) {

		publish(port);

		verify();

		return *this;

	}

	playground& verify() {

		console("https://vmnom.com");

		socklen_t len = sizeof(addr);

		if (getsockname(fd, reinterpret_cast<sockaddr*>(&addr), &len) != -1) {

			console("0.0.0.0:" + to_string(ntohs(addr.sin_port)));

		} else {

			perror("getsockname");

			exit(EXIT_FAILURE);
		}

		return *this;

	}

};

#endif
