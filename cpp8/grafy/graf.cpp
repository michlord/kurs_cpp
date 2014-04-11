#include "graf.h"

#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
Graf::Graf () throw(){
    ilosc_w = 0;
    graf = nullptr;
}
Graf::Graf (int n) throw(ujemna_liczba_wierzcholkow){
    ilosc_w = n;
    if(ilosc_w<0)
        throw ujemna_liczba_wierzcholkow();
    graf = new std::vector<int>[ilosc_w];
}
Graf::Graf (int n, std::vector<std::pair<int,int>> kraw) throw(ujemna_liczba_wierzcholkow, nieprawidlowa_krawedz){
    ilosc_w = n;
    if(ilosc_w<0)
        throw ujemna_liczba_wierzcholkow();
    graf = new std::vector<int>[ilosc_w];
    for(auto it = kraw.begin(); it!=kraw.end(); ++it){
        *this += *it;
    }
}
Graf::Graf (const Graf &g) throw(){
    ilosc_w = g.ilosc_w;
    graf = new std::vector<int>[ilosc_w];
    std::copy(g.graf,g.graf+ilosc_w,graf);
}
Graf & Graf::operator= (const Graf &g) throw(){
    if(this == &g)
        return *this;
    ilosc_w = g.ilosc_w;
    if(graf != nullptr)
        delete [] graf;
    graf = new std::vector<int>[ilosc_w];
    std::copy(g.graf,g.graf+ilosc_w,graf);
    return *this;
}
Graf::~Graf () throw(){
}
Graf & Graf::operator+= (std::pair<int,int> kraw) throw(nieprawidlowa_krawedz){
    if(kraw.first < 0 || kraw.first >= ilosc_w ||
       kraw.second < 0 || kraw.second >= ilosc_w)
        throw nieprawidlowa_krawedz();
    auto it1 = std::find(graf[kraw.first].begin(),graf[kraw.first].end(),kraw.second);
    auto it2 = std::find(graf[kraw.second].begin(),graf[kraw.second].end(),kraw.first);
    if(it1 != graf[kraw.first].end() || it2 != graf[kraw.second].end())
        return *this;
        //throw nieprawidlowa_krawedz(); //nie wkladamy duplikatow
    graf[kraw.first].push_back(kraw.second);
    graf[kraw.second].push_back(kraw.first);
    return *this;
}
Graf & Graf::operator-= (std::pair<int,int> kraw) throw(nieprawidlowa_krawedz){
    if(kraw.first < 0 || kraw.first >= ilosc_w ||
       kraw.second < 0 || kraw.second >= ilosc_w)
        throw nieprawidlowa_krawedz();
    auto it1 = std::find(graf[kraw.first].begin(),graf[kraw.first].end(),kraw.second);
    auto it2 = std::find(graf[kraw.second].begin(),graf[kraw.second].end(),kraw.first);
    if(it1 == graf[kraw.first].end() || it2 == graf[kraw.second].end())
        throw nieprawidlowa_krawedz();
    std::iter_swap(it1,graf[kraw.first].end()-1);
    std::iter_swap(it2,graf[kraw.second].end()-1);
    graf[kraw.first].pop_back();
    graf[kraw.second].pop_back();
    return *this;
}
std::istream & operator>> (std::istream &we, Graf &x){
    int n;
    we >> n;
    int k;
    we >> k;
    x = Graf(n);
    while(k--){
        int a,b;
        we >> a >> b;
        x += std::make_pair(a,b);
    }
    return we;
}
std::ostream & operator<< (std::ostream &wy, const Graf &x){
    wy << "Ilosc wierzcholkow: " << x.ilosc_w << std::endl;
    wy << "Krawedzie: " << std::endl;
    for(int i=0;i<x.ilosc_w;++i){
        wy << i << ": ";
        for(auto it = x.graf[i].begin(); it != x.graf[i].end(); ++it){
            wy << *it << ", ";
        }
        wy << std::endl;
    }
    return wy;
}
/*
void Graf::dfs(int start,void (*f)(int)){
    if( start < 0 || start >= ilosc_w)
        return;
    bool *visited = new bool[ilosc_w];
    std::fill(visited,visited+ilosc_w,false);
    std::stack<int> s;
    s.push(start);
    while(s.empty() == false){
        int v = s.top();
        s.pop();
        if(visited[v] == true)
            continue;
        visited[v] = true;
        f(v);
        for(auto it = graf[v].begin();it != graf[v].end();++it){
            int t = *it;
            if(visited[t] == true)
                continue;
            s.push(t);
        }
    }
    delete [] visited;
}
void Graf::bfs(int start,void (*f)(int)){
    if( start < 0 || start >= ilosc_w)
        return;
    bool *visited = new bool[ilosc_w];
    std::fill(visited,visited+ilosc_w,false);
    std::queue<int> s;
    s.push(start);
    while(s.empty() == false){
        int v = s.front();
        s.pop();
        if(visited[v] == true)
            continue;
        visited[v] = true;
        f(v);
        for(auto it = graf[v].begin();it != graf[v].end();++it){
            int t = *it;
            if(visited[t] == true)
                continue;
            s.push(t);
        }
    }
    delete [] visited;
}*/

