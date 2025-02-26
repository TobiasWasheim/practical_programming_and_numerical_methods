#include<iostream>
#include<cmath>
#include<string>
#include"vec.h"
#define SELF (*this)

vec& vec::operator+=(const vec& other){
	x+=other.x;
	y+=other.y;
	z+=other.z;
	return (*this);
}

vec& vec::operator-=(const vec& other){
	x-=other.x;
	y-=other.y;
	z-=other.z;
	return (*this);
}

vec& vec::operator*=(double n){
	x*=n;
	y*=n;
	z*=n;
	return (*this);
}

vec& vec::operator/=(double n){
	x/=n;
	y/=n;
	z/=n;
	return (*this);
}

vec operator+(const vec& a, const vec& b){
	vec r=a;
	r+=b;
	return r;
}

vec operator-(const vec& a){
	vec r=a;
	r.x=-r.x;
	r.y=-r.y;
	r.z=-r.z;
	return r;
}

vec operator-(const vec& a, const vec& b){
	vec r=a;
	r-=b;
	return r;
}

vec operator*(const vec& a, double n){
	vec r=a;
	r*=n;
	return r;
}

vec operator*(double n, const vec& a){
	vec r=a;
	r*=n;
	return r;
}

void vec::print(std::string s) const {
    std::cout << s << x << " " << y << " " << z << std::endl;
    }

double vec::dot (vec& other) {
    return x*other.x+y*other.y+z*other.z; 
}