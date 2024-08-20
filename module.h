#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <Windows.h>
#include <stdio.h>

using namespace std;

struct Book;
int inputFailCheck();
void printFile(fstream& file, int& books_written);
void addRow(fstream& file, int& books_written);
void search(fstream& file, int& books_written);