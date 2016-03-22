# programming-assignment-1-ytlin
programming-assignment-1-ytlin created by Classroom for GitHub

# Performance comparison

用來測試排序的數列長度為100000﹐由99999~0依序排列(worst case)
﹐利用三種quiksort來排序此數列﹐因為每次執行時間都會不太一樣﹐而Prog2.cpp , Prog3.cpp的速度又沒有差太大﹐所以我連續執行10次﹐結果如下(單位為秒)：

##Prog-1.cpp
![Foo](https://github.com/NCTU-CSE-Introduction-to-Algorithms/programming-assignment-1-ytlin/blob/master/screenshot/p1.png)

##Prog-2.cpp
![foo](https://github.com/NCTU-CSE-Introduction-to-Algorithms/programming-assignment-1-ytlin/blob/master/screenshot/p2.png)

##Prog-3.cpp
![foo](https://github.com/NCTU-CSE-Introduction-to-Algorithms/programming-assignment-1-ytlin/blob/master/screenshot/p3.png)

# Conclution

由以上結果可以看出Prog2.cpp , Prog3.cpp的改良大幅增加了排序時間。
而整體而言Prog3.cpp表現又比Prog2.cpp來的好。

**表現： Prog3.cpp > Prog2.cpp >Prog1.cpp**

由此可見選基準值(Pivot)對quiksort的重要性。
