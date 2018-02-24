import gym
from random import *

class Gene(object):
	# Quando for necessário, criar mais métodos get e set e outros
    def __init__(self,x,y,corda = "",pont = 0,MAX = 2000,P_Mut = 5): 
        self.corda = corda
        self.pont = pont
        self.MAX = MAX
        self.x = x
        self.y = y
        self.P_Mut = P_Mut
	#Criar método para me retornar a frequência da Ação
    def getCorda(self):
        return self.corda

    def getMut(self):
        return self.P_Mut
    	
    def getPont(self):
        return self.pont
		
    def getMAX(self):
        return self.MAX
        
    def getX(self):
        return self.x
		
    def getY(self):
        return self.y

    def getFreq(self):#
        freq = []
        cont1 = cont2 = cont3 = 0
        for j in range(self.getMAX()):
            if(int(self.getCorda()[j]) == 0):#tirar o i para fazer melhor
                cont1 += 1
            if(int(self.getCorda()[j]) == 1):
                cont2 += 1
            if(int(self.getCorda()[j]) == 2):
                cont3 += 1
        freq.append(cont1)
        freq.append(cont2)
        freq.append(cont3)
        return freq
                
    
    def setPont(self,pont):
        self.pont = pont
		
    def setMAX(self,MAX):
        self.MAX = MAX
	
    def preencher_G(self):#método para quando a corda é vazia
        for i in range(self.getMAX()):
                self.corda += str(randint(self.getX(),self.getY()))# tirar o i para fazer melhor
                
    def cross(self,Gene):
        corda = ""
        x = randint(0,self.getMAX()-1)
        for i in range(x):
            corda += self.getCorda()[i]#tirar o i para fazer melhor
        for i in range(x,self.getMAX()):
            corda += Gene.getCorda()[i]
        fator_mutacao = randint(1,100)
        if(k>=1 and k<= self.getP_Mut()):
                self.corda[randint(0,1999)] = randint(self.getX(),self.getY()) #modificar o tipo de mutação    
        return corda

    def __str__(self):
            return ("Genoma: "+self.getCorda()+"\n"+"Pontuacao: "+str(self.getPont())+ " // "+
                    "Acoes: de "+str(self.getX())+" a "+str(self.getY()) + " // " + "Frequencia: " + str(self.getFreq()))
        
    def __eq__(self,Gene):
        return self.getCorda() == Gene.getCorda()
    
    def __lt__(self,Gene):
        return self.getPont() < Gene.getPont()


class MaquinaGenetica(object):
        # Quando for necessário, criar mais métodos get e set e outros
        def __init__(self,numeroacao,populacao = [],size=50,P_DeadGene = 40):
                self.populacao = populacao
                self.size = size
                self.geracao = 0
                self.numeroacao = numeroacao
                self.P_DeadGene = P_DeadGene
                
        def getPop(self):
                return self.populacao

        def getPDC(self):
            return self.P_DeadGene

        def getSize(self):
                return self.size

        def getGer(self):
                return self.geracao

        def getNumAc(self):
            return self.numeroacao
        
        def getMasterGene():
            lista = self.getPop()
            lista.sort()
            return lista[self.getSize() - 1]


        def setPop(self,populacao):
                self.populacao = populacao

        def setSize(self,size):
                self.size = size

        def setGer(self,geracao):
                self.geracao = geracao

        def preencher(self):
            pass

        def adaptar(self,P_DeadGene):#meche com a polpulacao,Criar dois tipos de Crossover, dois tipos de adaptação dois tipos de mutação
            lista = self.getPop()
            lista.sort()
            for i in range(int((P_DeadGene/100)*self.getSize())):# tirar o i para fazer menor 
                lista[i] = self.getPop()[randint(int((P_DeadGene/100)*self.getSize()),self.getSize()-1)]
            for i in range(int((P_DeadGene/100)*self.getSize())):
                self.populacao[i] = lista[i]
		
        def selecao(self):
            self.adaptar(self.getPDC())
            lista =[]
            for _ in range(int((self.getSize()/2))):
                x = self.getPop()[randint(0,self.getSize()-1)]
                y = self.getPop()[randint(0,self.getSize()-1)]
                Gx = Gene(0,2,x.cross(y))
                Gy = Gene(0,2,y.cross(x))
                lista.append(Gx)
                lista.append(Gy)
            self.setPop(lista)
            self.setGer(self.getGer()+1)
            
        def preencher(self):#método para quando a corda é vazia
            for i in range(self.getSize()):#tirar o i para fazer um método menor
                x = Gene(0,self.getNumAc())
                x.preencher_G()
                self.populacao.append(x)

        def __str__(self):#
            pop = ""
            fm = ""
            m1 = 0
            m2 = 0
            m3 = 0
            for g in self.getPop():
                pop += g.__str__() + "\n"
                
            for i in range(self.getSize()):
                m1+= self.getPop()[i].getFreq()[0]
            m1 /= self.getSize()
            fm += str(m1) + ", "
            
            for i in range(self.getSize()):
                m2+= self.getPop()[i].getFreq()[1]
            m2 /= self.getSize()
            fm += str(m2) + ", "
            
            for i in range(self.getSize()):
                m3+= self.getPop()[i].getFreq()[2]
            m3 /= self.getSize()
            fm += str(m3) 
            
            return ("\nGeracao: "+str(self.getGer())+"\n"+pop+"\n" + "Frequencia Média: " + fm + "\n")
                    #+"MasterGene: "+self.getMasterGene())
            #Utilizar NumPy para gerar gráficos das média das frequências do conjunto de ações
            #Colocar a parada para quando atingir o objetivo
            #Ver a Questão do Master Gene e o Gene Objetivo
                    
   
MGMC = MaquinaGenetica(2)
MGMC.preencher()
env = gym.make('MountainCar-v0')
env.reset()
'''lista = "20222100212122221021001100010011122211121112110210011102212221220012211100211211010101000001111111000102101220112020110210020011001210011111020212202122221121102120121010001120012120010020112221220022011121212200212011222021020112202102220211010210220122221222220201112112211021220102012112222011212212010211200022122210000001002020011102012012000122200012220202221120200220012101202122122211212002221010102121221020200120220021101120202102222202110211112001110211110112022202221000111010102200211221011201222211222101102222101200122100201010110010022200200211002120121110002020212111120002011100010112212200001021102120100010121022200010122220112121002100220220001120220200021120020002221111001120220001200221011200211101002212211002211021011000102000200011202000120020120021011010221020111011211021201221100110211211212220001201201221201212122020021022022100220002012120000000100210100220110202110212121220002201010210212101111212210222001222011012111011211121002021100211110200121202220221100202010022201202020211201210211222212111011020020110121121101211102220121001012111102121121111110212102002021021220110111022222002010210212000012210200210102022101210121210011111120122110002210221021220212111111201121112001122121020011010120021122021121202121000101201021012000210021212001121011120021201210201121220021110022102000200121200201012201012100021212021122021112022211112212210022011221101011111211011021102111112112121201121010212212010022002111021220200220000201001122012210220101202000210021020220022100102021121100020220102210120121120200000120000221110010221001212111120112222000111021001200120200100012011200100202002112101211111101210100110021222121012100212112000001120120020221212210221202020212211111111020011212110011002000010000022201101222211220200211002101112011221010102202121110020121011100100020022202021202121120010112222121111120212202222112121001222122011101021212010011010210212002120002121012011022122102212020201112011010001100222121200121102022010020112220101222200111022"
for i in range(2000):
    env.render()
    obs,x,y,z=env.step(int(lista[i]))
    altura,k = obs
    if(altura == 0.6):
        exit()'''
recompensaGene = -6
print("\nGeracao: " + str(MGMC.getGer()) + "\n\n")
lista_de_geracoes = []
aux = 0
#for _ in range(50):
Lista_Objetivo = []
for _ in range(50):
    for Gen in MGMC.getPop():
        for i in range(Gen.getMAX()):
            env.render()
            visao, recompensa, y, z = env.step(int(Gen.getCorda()[i]))
            altura,k = visao
            if(altura > recompensaGene):
                recompensaGene = altura  #depois modificar para um outro parametro//fazer uma lógica utilizando goalposition(0.5)
            if(altura == 0.6):
                aux += 1
                break
                    #lista_de_geracoes.append(MGMC.getGer())
                    #aux += 1
                    #break
            #if(aux == 1):
                #break
        Gen.setPont(recompensaGene)
        print(Gen)
        recompensaGene = -6
        env.reset()
        #if(aux == 1):
            #break
        #print(MGMC)
    Lista_Objetivo.append(aux)
    aux = 0
    MGMC.selecao()
    env.reset()
    print("\nGeracao: " + str(MGMC.getGer()) + "\n\n")

print("\n\n" + str(Lista_Objetivo)+ "\n\n")


#O fato do algorítimo considerar a pontuação só até ele conseguir o objetivo faz com que ele não material lixo do geno-
#ma e gere uma falsa pontuação invalidando o gene, fazendo a seleção ser errada
#O grafico é Geração por Quantidade de Objetivos Atingindos
#O agente vai aprendendo que para atingir o objetivo ele deve pegar cada vez mais velocidade, para ganhar mais altura		
#Esse parametro da altura é relativo pois em determinado ponto alturas maiores não atingem o objetivo, mas algumas alturas
#menores atingem(somatório)
