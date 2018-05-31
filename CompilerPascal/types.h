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
		EnumEveryList enumt;		//枚举类型(枚举类型的每个元素的Type为ENUM，但是union部分不定义)
		struct 
		{
			S_symbol sym;			//如果是用户自定义类型，这里可以发挥作用
			Type ty;
		} name;
	} u;
};

struct array{
	Type ty;							//下标的类型
	Type tyEle;						//数组中每个元素的类型
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
//	A_ty		 type;				//存储数组的下标
//	A_exp arrayExp;				//存储数组语法解析之后的内容，方便递归
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
Type ARRAY_type(Array arrayInfo);				//新增数组
Type ENUM_type(EnumEveryList enumt);		//新增枚举类型
Type NAME_type(S_symbol sym, Type ty);

Typelist Newtypelist(Type head,Typelist next);
Field Newfield(S_symbol name, Type ty);
Fieldlist Newfieldlist(Field head,Fieldlist next);

EnumEvery NewEnumEvery(S_symbol name);
EnumEveryList NewEnumEveryList(EnumEvery head, EnumEveryList next);


void Typeprint(Type ty);
void Typelistprint(Typelist list);

#endif
