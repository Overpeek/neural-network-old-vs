#pragma once

#include <cstdio>
#include <iostream>
#include <string>

namespace oe {

	class BinaryIO {
	public:
		template<typename T> static void write(std::string name, void* data, size_t dataSize) {
			FILE *pFile = fopen(name.c_str(), "wb");
			if (pFile == NULL) { std::cout << "FAILED TO WRITE" << std::endl; exit(0); }
			fwrite(data, sizeof(T), dataSize, pFile);
			fclose(pFile);
		}

		template<typename T> static T* read(std::string name, unsigned long &lenght) {
			FILE *pFile;
			//long lSize;
			T *buffer;
			size_t result;

			pFile = fopen(name.c_str(), "rb");
			if (pFile == NULL) return nullptr;

			fseek(pFile, 0, SEEK_END);
			lenght = ftell(pFile);
			rewind(pFile);

			buffer = (T*)malloc(sizeof(T)*lenght);
			if (buffer == NULL) return nullptr;

			result = fread(buffer, 1, lenght, pFile);
			if (result != lenght) return nullptr;

			fclose(pFile);

			lenght /= sizeof(T);
			return buffer;
		}
	};

}