# Car-plate-number
NEU Datastructure    
汽车牌照的快速查询
【问题描述】
在汽车数据的信息模型中，汽车牌照是具有结构特点的一类关键字。汽车牌照是字母和数字混编的，例如01B7238。利用查找和排序算法，实现辽宁省内汽车牌照的快速查找。
【设计要求】
设计汽车牌照的快速查询程序。
（1）采用顺序表、静态链表等数据结构。
（2）可以随机、文件及人工输入数据。
（3）利用静态链表对汽车牌照进行链式基数排序。
（4）采用折半查找汽车牌照。
（5）可以按城市进行分块索引查找。
（6）其它完善性或扩展性功能。

**Data Structure**   
- Gasoline Car：A regional letter + Five license plates   
- Electromobile：A regional letter + Six license plates   

**Functions**    
（1）Inputing car plates in three ways(manual ,file and random generation)        
（2）Using static linked list to sort car license plate by chain radix        
（3）Searching the specific car license plate with binary search    
（4）Searching by block index by city    
（5）Perfect function: Each license plate initial 12 points, red light deduction 6 points, high-speed reverse deduction 12 points, milk dragon driving deduction 3 points. If the score is below 0, the license will be revoked    
