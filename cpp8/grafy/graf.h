#ifndef GRAF_H_
#define GRAF_H_

#include "graf_except.h"
#include <vector>
#include <utility>
#include <memory>
#include <iostream>

#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>



class Graf{
public:
    Graf () throw();
    Graf (int n) throw(ujemna_liczba_wierzcholkow);
    Graf (int n, std::vector<std::pair<int,int>> kraw) throw(ujemna_liczba_wierzcholkow, nieprawidlowa_krawedz);
    Graf (const Graf &g) throw();
    Graf & operator= (const Graf &g) throw();
    virtual ~Graf () throw();
    Graf & operator+= (std::pair<int,int> kraw) throw(nieprawidlowa_krawedz);
    Graf & operator-= (std::pair<int,int> kraw) throw(nieprawidlowa_krawedz);
    friend std::istream & operator>> (std::istream &we, Graf &x);
    friend std::ostream & operator<< (std::ostream &wy, const Graf &x);
    int ileWierzcholkow(){return ilosc_w;};
    //void dfs(int start,void (*f)(int));
    //void bfs(int start,void (*f)(int));

    template <typename fobj>
    void dfs(int start,fobj f){
        if( start < 0 || start >= ilosc_w)
            return;
        bool *visited = new bool[ilosc_w];
        std::fill(visited,visited+ilosc_w,false);
        std::stack<int> s;
        visited[start] = true;
        s.push(start);
        while(s.empty() == false){
            int v = s.top();
            s.pop();
            for(auto it = graf[v].begin();it != graf[v].end();++it){
                int t = *it;
                if(visited[t] == true)
                    continue;
                f(v,t);
                s.push(t);
                visited[t] = true;
            }
        }
        delete [] visited;
    }
    template <typename fobj>
    void dfs2(int start,fobj f){
        if( start < 0 || start >= ilosc_w)
            return;
        bool *visited = new bool[ilosc_w];
        std::fill(visited,visited+ilosc_w,false);
        std::stack<int> s;
        visited[start] = true;
        s.push(start);
        while(s.empty() == false){
            int v = s.top();
            s.pop();

            f(v);
            for(auto it = graf[v].begin();it != graf[v].end();++it){
                int t = *it;
                if(visited[t] == true)
                    continue;
                s.push(t);
                visited[t] = true;
            }
        }
        delete [] visited;
    }
    template <typename fobj>
    void bfs2(int start,fobj f){
        if( start < 0 || start >= ilosc_w)
        return;
        bool *visited = new bool[ilosc_w];
        std::fill(visited,visited+ilosc_w,false);
        std::queue<int> s;
        visited[start] = true;
        s.push(start);
        while(s.empty() == false){
            int v = s.front();
            s.pop();
            f(v);
            for(auto it = graf[v].begin();it != graf[v].end();++it){
                int t = *it;
                if(visited[t] == true)
                    continue;
                visited[t] = true;
                s.push(t);
            }
        }
        delete [] visited;
    }
private:
    int ilosc_w;
    std::vector<int> *graf;
};

#endif
