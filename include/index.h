#ifndef __INDEX_H__
#define __INDEX_H__

#include <iostream>
#include <fstream>
#include <string>
void print_diagonal(std::string txt, size_t size){
	size_t k;
	for(size_t i=0; i<size;i++){
		k = i;
		while(k<size*size){	
			std::cout<<txt[k];
		k = k + size + 1;
		}
	std::cout<<std::endl;
	}
}

void print_vertical(std::string txt, size_t size){
	size_t k;
	for(size_t i=0; i<size;i++){
		k = i;
		while(k<size*size){	
			std::cout<<txt[k];
		k = k + size;
		}
	std::cout<<std::endl;
	}

}
void print_original(std::string txt, size_t size){
	for(size_t i=0; i<=txt.size();i++){
		if(i%size == 0){
			std::cout<<std::endl;
		}
		std::cout<<txt[i];
	}		
}

size_t num_el(std::string file_path){
	size_t num = 0;	
	std::string buffer;
	std::fstream file_in;
	
	/**file io*/
	file_in.open(file_path, std::fstream::in);
	std::getline(file_in, buffer, '\n');
	file_in.close();
	
	/**read and increment num*/
	for(std::string::iterator it = buffer.begin(); it != buffer.end(); it++){
		num++;
	}	
	
	buffer.clear();
	return num;
}

bool input_file(std::string file_path){
	
	std::fstream file_in;
	std::string stream, txt;
	size_t size;
	size = num_el(file_path);

	file_in.open(file_path, std::fstream::in);
	if(!file_in.is_open()) return false;
	while(!file_in.eof()){
		std::getline(file_in, stream, '\n');
		if(stream.size() == size) txt+= stream;
		stream.clear();
	}
	
	print_original(txt, size);
	std::cout<<std::endl;
	print_vertical(txt, size);
	std::cout<<std::endl;
	print_diagonal(txt, size);
	file_in.close();
	return true;
}


#endif //__INDEX_H__
