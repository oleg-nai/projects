#pragma once
struct guy
{
	char* name;
	int phone;
};
struct List
{
	guy a;
	List* next;
};
void Vivod_V_File(List** begin);
void Init(List** begin);
void Print(List* s); 
void Insert(List** begin); 
void Delete(List** begin);
void Free(List** begin);
void Proverka(List** begin);
void Poisk(List** begin);
void Sort(List** begin); 
void Start(List** begin);
