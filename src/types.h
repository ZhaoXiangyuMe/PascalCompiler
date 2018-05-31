#ifndef TYPES_H
#define TYPES_H

typedef struct type *Type;
typedef struct typelist *Typelist;
typedef struct field *Field;
typedef struct fieldlist *Fieldlist;
typedef struct enumEvery *EnumEvery;
typedef struct enumEveryList *EnumEveryList;
typedef struct array	*Array;

struct type 
{
	enum {RECORD,NIL,BOOLEAN,INT,CHAR,STRING,ARRAY,REAL,NAME,VOID,ENUM} flag;
	union 
	{
		Fieldlist record;
		Array arrayInfo;
		EnumEveryList enumt;		//ö������(ö�����͵�ÿ��Ԫ�ص�TypeΪENUM������union���ֲ�����)
		struct 
		{
			S_symbol sym;			//������û��Զ������ͣ�������Է�������
			Type ty;
		} name;
	} u;
};

struct array{
	Type ty;							//�±������
	Type tyEle;						//������ÿ��Ԫ�ص�����
		union{
			struct{
				int start;
				int end;	
			}intt;
			struct{
				char start;
				char end;
			}charr;
			struct{
				S_symbol start;
				S_symbol end;
				S_symbol enumName;
			}enumm;
		}u;
//	A_ty		 type;				//�洢������±�
//	A_exp arrayExp;				//�洢�����﷨����֮������ݣ�����ݹ�
};

struct typelist {Type head; Typelist next;};
struct field {S_symbol name; Type ty;};
struct fieldlist {Field head; Fieldlist next;};

struct enumEvery {S_symbol name;};
struct enumEveryList {EnumEvery head; EnumEveryList next;};


Type NIL_type(void);
Type INT_type(void);
Type BOOLEAN_type(void);
Type CHAR_type(void);
Type STRING_type(void);
Type VOID_type(void);
Type REAL_type(void);

Type RECORD_type(Fieldlist record);
Type ARRAY_type(Array arrayInfo);				//��������
Type ENUM_type(EnumEveryList enumt);		//����ö������
Type NAME_type(S_symbol sym, Type ty);

Typelist Newtypelist(Type head,Typelist next);
Field Newfield(S_symbol name, Type ty);
Fieldlist Newfieldlist(Field head,Fieldlist next);

EnumEvery NewEnumEvery(S_symbol name);
EnumEveryList NewEnumEveryList(EnumEvery head, EnumEveryList next);


void Typeprint(Type ty);
void Typelistprint(Typelist list);

#endif
