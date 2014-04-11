#include <iostream>
#include <sstream>
#include "graf.h"
#include <functional>
#include <utility>
class drzewoRozpinajace{
public:
    drzewoRozpinajace(Graf g):drzewo(g.ileWierzcholkow()){
        bool *visited = new bool[g.ileWierzcholkow()];
        std::fill(visited,visited+g.ileWierzcholkow(),false);
        std::function<void(int,int)> f = [visited,this](int parent,int child){ visited[parent]=true;visited[child]=true;drzewo += std::make_pair(parent,child);};
        for(int i=0;i<g.ileWierzcholkow();++i){
            if(visited[i] == false)
            {
                g.dfs(i,f);
            }
        }
        delete [] visited;
    }
    Graf drzewo;
};

int main()
{
    std::auto_ptr<Graf> g(new Graf);
    std::stringstream s;
    s << "8 8 0 1 2 1 3 2 3 1 4 3 0 5 6 5 7 5";
    s >> *g;
    std::cout << *g;
    drzewoRozpinajace d(*g);
    std::cout << d.drzewo;


    //std::cin >> g;
    //std::cout << g;

    std::function<void(int)> f_display = [](int x){std::cout << x << " ";};
    g->dfs2(0,f_display);
    std::cout << std::endl;
    g->bfs2(0,f_display);

    return 0;
}
