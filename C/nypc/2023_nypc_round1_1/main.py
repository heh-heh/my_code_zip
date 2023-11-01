n = int(input())
job_list=[]
for i in range(0,n) : 
    job_list.append(input())
m = int(input())
job_list2=[]
for i in range(0,m) : 
    job_list2.append(input())


for i in range(0,m) :
    if job_list2[i] in job_list :
        job_list.remove(job_list2[i])

print(len(job_list))
for i in  range(0,len(job_list)) : 
    print(job_list[i])
