v = (first second)
(0 8)
(1 4)
(2 9)
(3 5)

store = (first second)
(0 8)
(1 4)
(2 9)
(3 5)

p[n]= {1,2,3,4} //processes

(in 0 ms/ shortest arrival time)
After P1 process executing 1 ms
store = (first second)
(0 7)
(1 4)
(2 9)
(3 5)

______________________
sorting
______________________
(here i = 0 j = 0)

for(i to n){

for(j to (n-i-1)){


}

}

(0 7)
(1 4)
(2 9)
(3 5)

when i = 2
and j iterating 0 to less than (4-2-1)-->1
{
for j = 1

if store[j].second>store[j+1].second (7>5)
change store: 
(0 7)
(1 4)
(2 9)
(3 5)

change V: 
(0 8)
(1 4)
(2 9)
(3 5)


change p: 
p[n]={2,1,4,3}

}
