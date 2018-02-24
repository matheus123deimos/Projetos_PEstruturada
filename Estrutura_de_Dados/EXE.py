from pilha1 import *


#def main():
p = Pilha(100)
Vect = []
cont = 0
sentenca = input("Digite a Sentença: ")#fazer como está no código em C depois ver uma maneira melhor
sentenca = sentenca.replace(" ","")
sentenca = (sentenca.replace("(","")).split(")")
while('' in sentenca): sentenca.remove('')
print(sentenca)
for c in sentenca:
    
    Num = c
    Sin = c
    if(not(c[0].isdigit())and len(c)>2): cont+=1
    for s in Sin:
        if(s.isdigit()): Sin = Sin.replace(s,"")
                
    if('+' in Num):
        for k in Num:
            if(k == '+'): Num = Num.replace(k,' ')

    if('-' in Num):
        for y in Num:
            if(y == '-'): Num = Num.replace(y,' ')
           
    if('/' in Num):
        for x in Num:
            if(x == '/'): Num = Num.replace(x,' ')

    if('*' in Num):
        for z in Num:
            if(z == '*'): Num = Num.replace(z,' ')

    Num = Num.split(" ")
    while('' in Num):Num.remove('')

    if(c[0].isdigit()):
        j = 0
        i = 0
        
        if(len(Num)>len(Sin)):
            for _ in range(len(Num)):
                Vect.append(Num[j])
                j+=1
                if(i<len(Num)-1):
                    Vect.append(Sin[i])
                    i+=1
        else:
            j = 0
            i = 0
            for itert in range(len(Num)):
                Vect.append(Num[j])
                j+=1
                Vect.append(Sin[i])
                i+=1
                        
    else:
        j = 0
        i = 0
        for _ in range(len(Num)):
            Vect.append(Sin[i])
            i+=1
            Vect.append(Num[j])
            j+=1

    Vect.append(')')

#print(str(len(Vect)))
#print(str(len(guard)))
#print(str(len(guard)-len(Vect)))
for _ in range(cont):Vect.append(')')
#print(Vect)
#(((0-5)+(4*4))-((3*17)/((4-3)+1)))
#print('\n\n'+str(len(Vect))+'\n\n')
for i in range(len(Vect)):
    if(Vect[i] == ')'):
        x = p.pop()
        y = p.pop()
        z = p.pop()

        
        if(y == "+"): p.push(x+z)
        elif(y == "-"): p.push(z-x)
        elif(y == "/"): p.push(z/x)
        else: p.push(x*z)
        print(p)
        #print('\n\n'+str(p.getTop())+'\n\n')

    elif(Vect[i].isdigit()):
        p.push(float(Vect[i]))
    else:
        p.push(Vect[i])
                
result = p.pop()
print("O resultado é: "+str(result))

s = input("Digite Enter para encerrar: ")
if(s == '\n'):
    exit(0)
    
#if __name__ == "__main__":
    #main()
