#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "Kraken2Plugin.h"

void Kraken2Plugin::input(std::string file) {
  inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void Kraken2Plugin::run() {
   
}

void Kraken2Plugin::output(std::string file) {
	//kraken2 --use-names --db ${KRAKEN2_DB} --paired --output taxa.krak2 R1.fastq R2.fastq
	//trim_galore --no_report_file --paired -o $out $reads_1 $reads_2
	std::string command = "kraken2 --use-names --db ${KRAKEN2_DB} --paired --output "+file+" "+std::string(PluginManager::prefix())+"/"+parameters["forward"]+" "+std::string(PluginManager::prefix())+"/"+parameters["reverse"];
 std::cout << command << std::endl;

 system(command.c_str());

}

PluginProxy<Kraken2Plugin> Kraken2PluginProxy = PluginProxy<Kraken2Plugin>("Kraken2", PluginManager::getInstance());
