#ifndef RWX_H
#define RWX_H

#include <simplify.h>

struct display {

	string buf;

	void clear() {

		system("clear");

	}
};

struct console : display {

	void log(string line) {

		cout << line << endl;

	}

};

struct socket {

	int id;

	sockaddr_in addr;
};

struct network : console {

	vector<socket> servers;

	using connection = map<clock_t, socket>;

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

	playground& enable(int port) {

		publish(port);

		verify();

		return *this;

	}

	playground& verify() {

		scale("https://vmnom.com");

		socklen_t len = sizeof(addr);

		if (getsockname(kernel, reinterpret_cast<sockaddr*>(&addr), &len) != -1) {

			console("0.0.0.0:" + to_string(ntohs(addr.sin_port)));

		} else {

			perror("getsockname");

			exit(EXIT_FAILURE);
		}

		return *this;

	}

	vector<int, nosql*> w;

	void (*workers) (vector<int, nosql*>*);
};

#endif
