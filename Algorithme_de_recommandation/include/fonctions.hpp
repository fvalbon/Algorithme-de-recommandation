#ifndef FONCTIONS_HPP
#define FONCTIONS_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <list>



int card_inter(std::vector<std::string> &U, std::vector<std::string> &V);

std::priority_queue<std::pair<int, std::pair<std::string, std::string> > > fnt_corr_optim(std::map<std::string, std::vector<std::string> > &data,int tau);


void mysort(std::list<int> &v, int card);
int get_element(std::list<int> &l, int position);
#endif
