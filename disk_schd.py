import numpy 
class disk_schd():
    def __init__(self):
        self.access=int(input("Enter the number of accesses"))
        print("Initialize sequence : ")
        self.access_seq=numpy.empty([10,1])
        for i in range (0,self.access): 
            int(input(self.access_seq[i]))
        head=int(input("Enter the header postion : "))
        seek=0
    def main():
        i=0
        while(i<1):
            choice=int(input("""Enter your choice : 1.FCFS \n 2.SSTF \n 3.SCAN"""))
            if(choice==1):
                result=fcfs()
            elif(choice==2):
                result=sstf()
            elif(choice==3):
                result=scan()
            else:
                print("Invalid Entry")
            i+=1
        print(result)
    def scan():
        access=incr(access)
        for i in range(0,access):
            if(access_seq[i]<head):
                x=i
                break;
        for i in range(x,access):
            seek+=abs(head-access_seq[i])
            head=access_seq[i];
        return seek;
    def display(self):
        print("\n\tSeek Time = "+self.result)
    def fcfs():
        seek=0
disk_SCHD=disk_schd()   
            
