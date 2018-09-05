#include <iostream>
#include <vector>
#include <algorithm>

template <typename Collection,typename unop>
void for_each(Collection col, unop op){
    std::for_each(col.begin(),col.end(),op);
}

template <typename Collection,typename unop>
Collection map(Collection col,unop op) {
    std::transform(col.begin(),col.end(),col.begin(),op);
    return col;
}

template <typename Collection,typename binop>
Collection zip(Collection fc,Collection sc,binop op) {
    std::transform(fc.begin(),fc.end(),sc.begin(),fc.begin(),op);
    return fc;
}

template <typename Collection,typename Condition>
bool exists(Collection col,Condition con) {
    auto exist = std::find_if(col.begin(),col.end(),con);
    return exist != col.end();
}


template <typename Collection,typename Predicate>
Collection filterNot(Collection col,Predicate predicate) {
    auto returnIterator = std::remove_if(col.begin(),col.end(),predicate);
    col.erase(returnIterator,std::end(col));
    return col;
}

template <typename Collection,typename Predicate>
Collection filter(Collection col,Predicate predicate) {
    auto fnCol = filterNot(col,[predicate](typename Collection::value_type i) { return !predicate(i);});
    return fnCol;
}

int main()
{
    //helper println
    auto println = [](const char  *message){std::cout << message << std::endl;};

    auto lambda_echo = [](int i ) {std::cout << i << std::endl;};
    std::vector<int> col{20,24,37,42,23,45,37};

    //call foreach to print the vector
    println("running foreach");
    for_each(col,lambda_echo);

    // add one to each element
    println("running map operation");
    auto addOne = [] (int i) { return i+1;};
    auto returnCol = map(col,addOne);
    for_each(returnCol,lambda_echo);

    //zip operation
    println("running zip operation");
    auto zipAdd = [] (int a, int b){ return a+b;};
    std::vector<int> secondCol{40,22,22,24,23,45,34};
    auto zipCol = zip(col,secondCol,zipAdd);
    for_each(zipCol,lambda_echo);

    println("runnig exists");
    //prints 1 if true 0 if false
    std::cout << "value 20 exist= " << exists(col, [] (int value){ return value==20;}) << std::endl;
    std::cout << "value 43 exist= " << exists(col, [] (int value){ return value==43;}) << std::endl;

    println("running filterNot");
    auto filterCol = filterNot(col,[](int value){ return value==23;});
    for_each(filterCol,lambda_echo);

    println("running filter");
    auto filteredCol = filter(col,[](int value){ return value > 30;});
    for_each(filteredCol,lambda_echo);
}
