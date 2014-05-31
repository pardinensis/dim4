#include "utils.hpp"

#include <fstream>
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