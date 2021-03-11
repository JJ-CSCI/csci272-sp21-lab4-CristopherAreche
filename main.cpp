//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include <string>
#include "catch.hpp"
using Catch::Matchers::Equals;
using namespace std;
//------------------------------

// Fix the following class
class Complex{
private:
  int real;
  int imag;
public:
  Complex(int re=0, int im=0){
    this->real = re;
    this->imag = im;
  }

  int re(){
    return this->real;
  }
  int im(){
    return this->imag;
  }
  
  void operator>>(string &str){
    string s="<";
    s += to_string(this->real);
    s += ">";
    if(this->imag >=0){
      s += "+<";
      s += to_string(this->imag);
    }
    else{
      s += "-<"; 
      s += to_string(this->imag*-1);
    }
    s += ">i"; 
    str = s;
  }

  void operator<<(string &str){
    string s="";
    int i=1;
    while(str[i]!='>'){
      s += str[i];
      i++;
    }

    this->real = stoi(s);

    string s1 = "";
    i++;
    int sign = 1;
    if(str[i]=='-'){
      sign = -1;
    }
    i += 2;
    while(str[i]!='>'){
      s1 += str[i++];
    }

    this->imag = stoi(s1)*sign;
  }
};

int main(){
  Complex c, c2, c3;
  c.setRe(2);
  c.setIm(3);
  c2.setRe(-1);
  c2.setIm(-3);
    
  string s1;
  c>>s1;
    
  c3<<s1;
    
  cout<<s1<<endl;
  c2>>s1;
  cout<<s1<<endl;
  cout<<c3.getRe()<<" "<<c3.getIm()<<endl;
    return 0;
}   
//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Complex c;
        REQUIRE( c.re() == 0 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c2" ) {
        Complex c{1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c3" ) {
        Complex c{1,1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "o1" ) {
        Complex c; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("0+0i") );
    }
    SECTION( "o2" ) {
        Complex c{1, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("1+2i") );
    }
    SECTION( "o3" ) {
        Complex c{2, -2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("2-2i") );
    }
    SECTION( "o4" ) {
        Complex c{-2, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("-2+2i") );
    }
    SECTION( "p1" ) {
        Complex c;
        c << "1+1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "p2" ) {
        Complex c;
        c << "1-1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == -1 );
    }
    SECTION( "p3" ) {
        Complex c;
        c << "-1+0i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "p4" ) {
        Complex c;
        c << "-1-2i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == -2 );
    }
}
//------------------------------
