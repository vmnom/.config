#include <rwx.h>

extern "C" void nmap (service* ctrl) {

	/** router used by this.
	 *
	 * automaticly creates database if not exists;
	 */
	vector<router>* routes = ctrl->resolve("vmnom.com");

};
