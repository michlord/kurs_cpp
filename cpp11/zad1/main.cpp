#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>

//mozna pomyslec tez o takim czyms:
//http://www.two-sdg.demon.co.uk/curbralan/papers/WritingStreamManipulators.html
//xalloc - makes it possible to define custom flags for stream objects
//this allows to make 'Sticky' manipulators
//http://www.informit.com/articles/article.aspx?p=171014&seqNum=2
//http://stackoverflow.com/questions/799599/c-custom-stream-manipulator-that-changes-next-item-on-stream
//* The xalloc() function returns an index to the next unused flag.
//  The flag is represented by a long. Each time xalloc() is called, a new index is returned.
//* The iword() and pword() methods are used to set the value or query the value of the flag

namespace obliczenia{

    std::istream & clearline(std::istream & is){
        //int c;
        //while( is && (c = is.get())!=EOF && c!='\n' ) continue;
        while(is && is.get()!='\n');
        return is;
    }

    class ignore{
    public:
        ignore(int x_): x(x_){}
        std::istream &operator()(std::istream &is) const{
            int counter = x;
            while(is && is.get()!='\n' && counter>0) --counter;
            return is;
        }
    private:
        int x;
    };
    std::istream &operator>>(std::istream &is, ignore i){
        return i(is);
    }

    std::ostream & comma(std::ostream & os){
        return os << ", ";
    }
    std::ostream & colon(std::ostream & os){
        return os << ": ";
    }

    class index{
    public:
        index(int x_, int w_): x(x_), w(w_) {}
        std::ostream &operator()(std::ostream &os) const{
            os.fill(' ');
            os << "[" << std::setw(w) << x << "]";
            return os;
        }
    private:
        int x;
        int w;
    };
    std::ostream &operator<<(std::ostream &os, index i){
        return i(os);
    }

} //namespace obliczenia

int numberLength(int x){
    std::stringstream ss;
    ss << x;
    return ss.str().length();
}

void test(){
    std::vector< std::pair<std::string,int> > vec;
    int line_counter = 0;
    while (std::cin){
        std::string str;
        std::getline(std::cin,str);
        ++line_counter;
        vec.push_back(std::make_pair(str,line_counter));
    }
    std::sort(vec.begin(),vec.end());
    int max_n_size = numberLength(line_counter);
    for(auto it=vec.begin(); it!=vec.end(); ++it){
        std::cout << obliczenia::index((*it).second,max_n_size) << obliczenia::colon << (*it).first << std::endl;
    }
}

int main()
{
    //std::string in1, in2, in3;
    //std::cin >> in1 >> obliczenia::ignore(10) >> in2 >> in3;
    //std::cout << in1 << in2 << in3;

    //std::cout << obliczenia::index(123,5) << obliczenia::index(12345,5) << obliczenia::index(123456,5) << obliczenia::index(12,5);

    //podajemy linie tekstu a nastepnie na windowsie wciskamy ctrl z i enter
    test();

    return 0;
}
