#include "utils.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <chrono>


const std::string& LOGFILE = "logfile.log";


std::fstream fs;
std::chrono::steady_clock::time_point start_time;

void check() {
	static bool initialized = false;
	if (initialized) return;

	fs.open(LOGFILE, std::fstream::out);
	fs.clear();
	fs.close();

	fs.open(LOGFILE, std::fstream::out | std::fstream::app);

	start_time = std::chrono::steady_clock::now();
	initialized = true;
}

void log(const std::string& msg) {
	check();

	std::chrono::duration<double> time = std::chrono::steady_clock::now() - start_time;
	fs << "[" << std::setprecision(3) << std::fixed << time.count() << "] ";

	fs << msg << std::endl;
}


void error(const std::string& msg) {
	const std::string err = "[ERROR] " + msg;

	std::cerr << err << std::endl;
	log(err);

	exit(EXIT_FAILURE);
}

void info(const std::string& msg) {
	const std::string info = "[INFO] " + msg;

	std::cout << info << std::endl;
	log(info);
}



void count_fps(double update_interval, const std::function<void(const std::string&)>& output) {
	using namespace std::chrono;
	static auto last_check = steady_clock::now();
	static int n_counts = 0;
	duration<double> elapsed = steady_clock::now() - last_check;
	if (elapsed.count() > update_interval) {
		std::stringstream ss;
		ss << "FPS: " << std::setprecision(3) << std::fixed << n_counts / elapsed.count();
		output(ss.str());
		last_check = steady_clock::now();
		n_counts = 0;
	}
	++n_counts;
}