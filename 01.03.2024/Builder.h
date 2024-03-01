#pragma once
#include <iostream>
class CarBuilder;
class CarDocumentationBuilder;

class Builder {
public:
	void virtual buildDrive()=0;
	void virtual setModel()=0;
	void virtual setColor()=0;
	void virtual setBrand()=0;
};

class Car {
	friend class CarBuilder;
	std::string drive="1.5";
	std::string model="noname";
	std::string brand="noname";
	std::string color= "grey";
public:
	void show() {
		std::cout << drive << " " << model << " " << color << " " << brand << std::endl;
	}
};

class CarDocumentation {
	friend class CarDocumentationBuilder;
	std::string document = "";
public:
	void show() {
		std::cout << document;
	}
};

class CarDocumentationBuilder:public Builder {
	CarDocumentation doc;
public:
	void buildDrive(std::string drive) {
		doc.document = "Drive: "+drive+"; ";
	}
	void setModel(std::string model) {
		doc.document = "Model: " + model + "; ";
	}
	void setColor(std::string color) {
		doc.document = "Color: " + color + "; ";
	}
	void setBrand(std::string brand) {
		doc.document = "Brand: " + brand + "; ";
	}

};

class CarBuilder :public Builder {
	Car car;
public:
	void buildDrive(std::string drive){
		car.drive = drive;
	}
	void setModel(std::string model){
		car.model = model;
	}
	void setColor(std::string color){
		car.color = color;
	}
	void setBrand(std::string brand){
		car.brand = brand;
	}
	Car getResult() { return car; }
};

class Director {
public:
	Director() {}
	void makeSportCar(CarBuilder& cb){
		cb.buildDrive("");
		cb.setBrand("");
		cb.setColor("");
		cb.setModel(""); 
	}
	void makeBasicCar(CarBuilder* cb) {
		cb->buildDrive("");
		cb->setBrand("");
		cb->setColor("");
		cb->setModel("");
	}
};