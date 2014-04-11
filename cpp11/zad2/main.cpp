#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization

namespace obliczenia{

//Pliki tekstowe
class PlikWejsciowy{
public:
    PlikWejsciowy(const char* fname_){
        in.exceptions(std::ios::failbit|std::ios::badbit);
        in.open(fname_,std::ifstream::in);
    }
    virtual ~PlikWejsciowy(){
        if (in.is_open())
            in.close();
    }
    std::string getline(){
        std::string str;
        std::getline (in,str);
        return str;
    }
    int get(){
        return in.get();
    }
    int parseInt(){
        int val;
        in >> val;
        return val;
    }
    double parseDouble(){
        double val;
        in >> val;
        return val;
    }
    bool good(){
        return in.good();
    }
private:
    std::ifstream in;

    template <typename T>
    friend PlikWejsciowy &operator>>(PlikWejsciowy &wej, T &val);
};

template <typename T>
PlikWejsciowy &operator>>(PlikWejsciowy &wej, T &val){
    wej.in >> val;
    return wej;
}

class PlikWyjsciowy{
public:
    PlikWyjsciowy(const char* fname_){
        out.exceptions(std::ios::failbit|std::ios::badbit);
        out.open(fname_,std::ofstream::out | std::ofstream::trunc);
    }
    virtual ~PlikWyjsciowy(){
        if (out.is_open())
            out.close();
    }
    void writestr(const std::string &str){
        out << str;
    }
    void put(char c){
        out.put(c);
    }
    void writeInt(int v){
        out << v;
    }
    void writeDouble(double v){
        out << v;
    }
    void newline(){
        out << std::endl;
    }
    bool good(){
        return out.good();
    }
private:
    std::ofstream out;
    template <typename T>
    friend PlikWyjsciowy &operator<<(PlikWyjsciowy &wyj, const T &val);
};

template <typename T>
PlikWyjsciowy &operator<<(PlikWyjsciowy &wyj, const T &val){
    wyj.out << val;
    return wyj;
}

} //namespace obliczenia

void test(){
    obliczenia::PlikWejsciowy in("input.txt");
    obliczenia::PlikWyjsciowy out("output.txt");
    std::vector<double> numbers;
    try{
        while(in.good()){
            double number = in.parseDouble();
            numbers.push_back(number);
        }
        for(auto it = numbers.rbegin(); it != numbers.rend(); ++it){
            out << *it << " ";
        }
    }catch(std::ios_base::failure &e){
        std::cout << "Exception:" << e.what() << std::endl;
    }


}


int main()
{
    test();
    std::cout << "done!\n";
    /*
    std::string test;
    PlikWejsciowy in("test.txt");
    test = in.getline();
    std::cout << test;
    */
    /*
    std::string str1,str2,str3;
    obliczenia::PlikWejsciowy in("test.txt");
    in >> str1 >> str2 >> str3;
    std::cout << str1 << str2 << str3;

    obliczenia::PlikWyjsciowy out("test-out.txt");
    out << "Lalala" << 34 << "sfsdfsf";
    */
    return 0;
}
