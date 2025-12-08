class MyClass{};

MyClass my;

MyClass* GetMyClassInstance(){
    return &my;
}

// Modern C++ 新的开发范式，社区里的人物比较
// 加固

void function(){
    MyClass* p1 = GetMyClassInstance();
}

void function2(){
    MyClass* p2 = GetMyClassInstance();
}

int main(){
    MyClass* p3 = GetMyClassInstance();
}