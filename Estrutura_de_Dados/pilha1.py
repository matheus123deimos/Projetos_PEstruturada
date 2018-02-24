class Pilha(object):

    def __init__(self, MX):#Pensar em mais de um construtor com o uso do swap;Depois tratar com expressões lambda, e operadores ternarios para ficar menor
        self.MX = MX
        self.P = []
        self.top = 0
        self.tm = len(self.getP())

    def getMX(self):#Obter o valor do máximo
        return self.MX

    def getP(self):#Obter a lista
        return self.P

    def getTop(self):#Obter o topo da pilha
        return self.top

    def getTm(self):#Obter o tamanho atual da pilha
        return self.tm

    def isEmp(self):#Obter se a pilha está vazia
        return (self.getTm() == 0)

    def isFull(self):#Obter se a pilha está cheia
        return (self.getTm()== self.getMX())
    
    def setMX(self,MX):#modifica o máximo da pilha
        self.MX = MX

    def setP(self,P):#modifica a lista da pilha
        self.P = P

    def setTop(self,top):#modifica o topo da pilha
        self.top = top

    def setTm(self,tm):#modifica o tamanho atual da pilha
        self.tm = tm
        
    def swap(self,Pilha):#Troca os valores da pilha
        self.setMX(Pilha.getMX())
        self.setP(Pilha.getP())
        self.setTop(Pilha.getTop())
        self.setTm(Pilha.getTm())

    def push(self,element):#adiciona a pilha
        if(not(self.isFull())):
            self.setP(self.getP() + [element])
            self.setTm(self.getTm()+1)
            self.setTop(self.getP()[self.getTm()-1])
                
    def pop(self):#retira da pilha
        if(not(self.isEmp())):
            Top = self.getTop()
            self.setP(self.getP()[0:self.getTm()-1])
            self.setTm(self.getTm()-1)
            if(self.isEmp()):
                self.setTop(0)
                return Top
            else:
                self.setTop(self.getP()[self.getTm()-1])
                return Top
                

    def __str__(self):#retorna uma string da pilha
        return (str)(self.getP())
    

    def __eq__(self,Pilha):#compara a igualdade das pilhas
        return (self.getP()==Pilha.getP())and(self.getMX()==Pilha.getMX())


    def __lt__(self,Pilha):#Depois descobrir como é a regra de comparação das lsitas de python mesmo tamanho
        #Compa a maior e a menor pilha
        if(self.getMX()==Pilha.getMX()):
           return (self.getP()<Pilha.getP())
        else:
            return (self.getMX()<Pilha.getMX())

#Depois pensar em sobrecarregar operadores de + e -, pop e push de outras Pilhas
#usar funções anônimas
