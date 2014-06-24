#include "stdafx.h"
#include <vector>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
class Range
{
	char* range;//���� ������
public:
	Range(char* s);//�����������
	~Range();//����������
	void sendMessage();//������� ���������� ���������� �� ������
};
class Table
{
protected:
	char* colour;//����
	char* material;//��������
	double table_price;//���� �����
	double material_price;//���� ���������
	static int count;//������� �������� ������
	virtual void CountPrice() = 0;//����� ����������� �������,��������������� ���� �����
public:
	Table();//����������� �� ���������
	Table(char* colour,char* material,double material_price);//���������������� �����������
	virtual ~Table();//����������
	char* getColour()const;//���������� ����
	char* getMaterial()const;//���������� ��������
	double getTablePrice()const;//���������� ���� �����
	double getMaterialPrice()const;//���������� ���� ���������
	void setColour(char* color);//������������� ����
	void setMaterial(char* material);//������������� ��������
	void setMaterialPrice(double material_price);//������������� ���� ���������
	virtual ostream & output(ostream & os)const;//����� ����������� ������� ���������� ������ ������� ������
	virtual istream & input(istream & is);//����������� ������� ����� ������ ������� ������
	static void displayCount();//������� ���������� ���-�� �������� ������
	static void resetCount();//������� ������ �������� ���-�� �������� ������
};
class SquareTable:public Table
{
private:
	double width;//������ ����������
	double length;//����� ����������
	double high;//������ �����
	void CountPrice();//�������,��������������� ���� �����
public:
	SquareTable();//����������� �� ���������
	SquareTable(char* colour,char* material,double material_price,double width,double length,double high);//���������������� �����������
	//~SquareTable();//����������
	double getWidth()const;//���������� ������ ����������
	double getLength()const;//���������� ����� ����������
	double getHigh()const;//���������� ������ �����
	void setWidth(double width);//������������� ������ ����������
	void setLength(double length);//������������� ����� ����������
	void setHigh(double high);//������������� ������ �����
	ostream & output(ostream & os)const;//����������� ������� ���������� ������ ������� ������
	istream & input(istream & is);//����������� ������� ����� ������ ������� ������
};
class CircleTable:public Table
{
private:
	double r;//������ ����������
	int leg_amount;//���������� ����� �����
	void CountPrice();//�������,��������������� ���� �����
public:
	CircleTable();//����������� �� ���������
	CircleTable(char* colour,char* material,double material_price,double r,int leg_amount);//���������������� �����������
	//~CircleTable();//����������
	double getR()const;//���������� ������ ����������
	int getLegAmount()const;//���������� ���������� ����� �����
	void setR(double r);//������������� ������ ����������
	void setLegAmount(int leg_amount);//������������� ���������� ����� �����
	ostream & output(ostream & os)const;//����������� ������� ���������� ������ ������� ������
	istream & input(istream & is);//����������� ������� ����� ������ ������� ������
};
ostream & operator<<(ostream & os,const Table & T);//���������� ��������� ������ �� ������
istream & operator>>(istream & is,Table & T);//���������� ��������� ����� � �����
double TotalPrice(vector <Table *> & v);//������� �������� ����� ���� ������ �������
