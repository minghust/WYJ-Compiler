//
// Created by MingZhang on 2018-05-18
//

#include "symbolTable.h"


vector<ClassTable> class_table;
vector<ParameterTable> parameter_table;
vector<FunctionTable> function_table;
vector<VariableTable> variable_table;

void addClass(string class_name)
{
    ClassTable entry;
    entry.class_name = class_name;
    entry.type_name = "class";
    class_table.push_back(entry);
}

void addVariable(string var_name, string var_type)
{
    VariableTable entry;
    entry.var_name = var_name;
    entry.var_type = var_type;
    variable_table.push_back(entry);
}

void addFunction(string func_name, string return_type, vector<ParameterTable> &para_list)
{
    FunctionTable entry;
    entry.function_name = func_name;
    entry.return_type = return_type;
    entry.para_list = para_list;
    function_table.push_back(entry);
}

void displayTable()
{
    cout << endl << endl << ">>>>>>>> Symbol Table <<<<<<<<<" << endl << endl;

    cout << "--------- class table ----------" << endl;
    // 14 9 13
    cout << setiosflags(ios::left) << setw(14) << "name" << resetiosflags(ios::left)
         << setiosflags(ios::right) << setw(9) << "type" << resetiosflags(ios::right) << endl;
    cout << "--------------------------------" << endl;
    for(int i=0; i<class_table.size(); i++) 
    {
        cout << setiosflags(ios::left) << setw(14) << class_table[i].class_name << resetiosflags(ios::left)
        << setiosflags(ios::right) << setw(9) << class_table[i].type_name << resetiosflags(ios::right) << endl;
    }
    cout << "--------------------------------" << endl << endl << endl;



    cout << "--------- variable table ---------" << endl;
    cout << setiosflags(ios::left) << setw(14) << "name" << resetiosflags(ios::left)
         << setiosflags(ios::right) << setw(9) << "type" << resetiosflags(ios::right) << endl;
    cout << "----------------------------------" << endl;

    for(int i=0; i<variable_table.size(); i++) 
    {
        cout << setiosflags(ios::left) << setw(14) << variable_table[i].var_name << resetiosflags(ios::left)
        << setiosflags(ios::right) << setw(9) << variable_table[i].var_type << resetiosflags(ios::right) << endl;
    }
    cout << "----------------------------------" << endl << endl << endl;


    cout << "-------------------- function table -----------------------" << endl;
    cout << setiosflags(ios::left) << setw(14) << "name" << resetiosflags(ios::left)
         << setiosflags(ios::right) << setw(9) << "type" << setw(30) << "parameter list(name: type)" << resetiosflags(ios::right) << endl;
    cout << "-----------------------------------------------------------" << endl;
    
    for(int i=0;i<function_table.size(); i++)
    {
        cout << setiosflags(ios::left) << setw(14) << function_table[i].function_name << resetiosflags(ios::left)
        << setiosflags(ios::right) << setw(9) << function_table[i].return_type << resetiosflags(ios::right);
        cout << "    ";
        for(int j=0;j<function_table[i].para_list.size();j++)
        {
            
            cout << function_table[i].para_list[j].para_name << ": " << function_table[i].para_list[j].para_type;
            if(j!=function_table[i].para_list.size()-1)
                cout << ",  ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}