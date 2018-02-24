import pygame
from pygame.locals import * 
from sys import exit
from math import *

class Vetor_2d(object):
    
    def __init__(self,x,y):
        
        self.x = float(x)
        self.y = float(y)
        self._v = [float(x),float(y)]
		
    def get_item(self,index):
        return self._v[index]
		
    def get_vetor(self):
        return self._v
		
    def set_item(self,index,numero):
        if index == 0:
            self.x = 1.0*numero
        elif index == 1:
            self.y = 1.0*numero
        else:
            pass
		
    def set_vetor(self,vetor):
        self.set_item(0,vetor[0])
        self.set_item(1,vetor[1])
        self._v = vetor
		
    def set_Vetor_2d(self,Vetor_2d):
        self.set_vetor(Vetor_2d.get_vetor())
			
    def get_intensidade(self):
        return sqrt(pow(self.get_item(0),2) + pow(self.get_item(1),2))
		
    def normalizar(self):
            
        try:
            vetor = [self.get_item(0)/self.get_intensidade(),self.get_item(1)/self.get_intensidade()]
            self.set_vetor(vetor)

        except ZeroDivisionError:
            self.set_vetor([0,0])
            
    def get_v_unit(self):
        vetor = Vetor_2d(self.get_item(0),self.get_item(1))
        vetor.normalizar()
        return vetor

    def get_link(vetor1,vetor2):#
        return Vetor_2d(vetor1.get_item(0) - vetor2.get_item(0), vetor1.get_item(1) - vetor2.get_item(1))
    

    def __str__(self):
        return "(%f,%f)"%(self.get_item(0),self.get_item(1))
    
    def __add__(self, vetor):
        return Vetor_2d(self.get_item(0) + vetor.get_item(0),self.get_item(1) + vetor.get_item(1))
    
    def __sub__(self, vetor):
        
        return Vetor_2d(self.get_item(0) - vetor.get_item(0),self.get_item(1) - vetor.get_item(1))
        
    def __neg__(self):
        
        return Vetor_2d(-self.get_item(0),-self.get_item(1))
    
    def __mul__(self,numero):
		
        return Vetor_2d(numero*self.get_item(0),numero*self.get_item(1))

    def __truediv__(self,numero):
        
        return Vetor_2d(self.get_item(0)/numero,self.get_item(1)/numero)

    def __eq__(self,vetor):

        return (self.get_item(0)==vetor.get_item(0) and self.get_item(1)==vetor.get_item(1)
               and self.get_vetor()==vetor.get_vetor())





class MiniMundo(object):#No futuro transformar esta classe em uma classe mãe

    def __init__(self,imagem,AREA,nome, seres = {}):

        self.seres = seres
        self.ser_id = 0
        self.imagem = imagem
        self.AREA = AREA
        self.nome = nome
        
        pygame.init()
        
        self.background = pygame.image.load(self.get_Imagem()).convert()

        self.screen = pygame.display.set_mode(self.get_AREA(),RESIZABLE,32)#tratar o redimensionamento 


    def Adicionar_Ser(self,ser):
        
        self.seres[self.ser_id] = ser
        ser.id = self.ser_id
        self.ser_id+= 1


    def Adicionar_ListaSer(self,listaser):
        
        for i in range(0,len(listaser)-1):
            self.Adicionar_Ser(listaser[i])


    def Remover_Ser(self, ser):
        
        del self.seres[ser.id]


    def Remover_ListaSer(self,listaser):

        for i in range(0,len(listaser)-1):
            self.Remover_Ser(listaser[i])

    def get(self,ser_id):
        
        if ser_id in self.seres:
    
            return self.seres[ser_id]
	
        else:
            
            return None

    def get_Nome():

        return self.mundo
    
    def get_Seres(self):

        return self.seres
    
    def get_ListaSeres(self,listaser_id1,listaser_id2):

        lista = []
        
        for i in range(listaser_id1,listaser_id2):
            lista.append(self.get(i))

        return lista

    def get_Ser_id(self):

        return self.ser_id

    def get_Imagem(self):

        return self.imagem

    def get_AREA(self):

        return self.AREA

    def get_Background(self):

        return self.background

    def get_Screen(self):

        return self.screen

    def set_Nome(self,NovoNome):

        self.nome = NovoNome
    
    def set_Fundo1(self,imagem,AREA):
        
       if imagem != self.get_Imagem() and imagem != 0:
           self.background = pygame.image.load(imagem).convert()
       if AREA != self.get_AREA() and AREA != 0:
           self.screen = pygame.display.set_mode(AREA,RESIZABLE,32)

    def set_Ser(self,ser_id,novoser):

        self.seres[ser_id] = novoser
    
    def set_Seres(self,novosseres):

        self.seres = novosseres

    
    def set_Ser_id(self,novoid):

        self.ser_id = novoid


    def set_Minimundo(self,NovoMiniMundo):

        if self.get_Seres() != NovoMininiMundo.get_Seres() and NovoMininiMundo.get_Seres() != 0:
            self.set_Seres(NovoMiniMundo.get_Seres())

        if self.get_Ser_id() != NovoMininiMundo.get_Ser_id() and NovoMininiMundo.get_Ser_id() != 0:
            self.set_Ser_id(NovoMiniMundo.get_Ser_id())

        if ((self.get_Background() != NovoMininiMundo.get_Background() or self.get_AREA() != NovoMiniMundo.get_AREA())
        and (NovoMininiMundo.get_Background() != 0 or NovoMininiMundo.get_Imagem())):
            self.set_Fundo1(NovoMiniMundo.get_Imagem(),NovoMiniMundo.get_AREA())

        if self.get_Nome() != NovoMininiMundo.get_Nome() and NovoMininiMundo.get_Nome() != 0:
            self.set_Nome(NovoMiniMundo.get_Nome())


    def __str__(self):

        controle = ""
        for ser in list(self.get_Seres().values()):
            controle += ser

        return ((35*" ")+ self.get_Nome() + (35*" ")+"\n"+ (80*"-") +"\n" + "Quantidade: "
        + len(self.get_Seres()) + "Id Atual: " + self.get_Ser_id() + "Area: " + self.get_AREA()
        + "Imagem: " + self.get_Imagem() + "\n\n" + controle)

    def processar(self,tempo_passado):

        for ser in list(self.get_Seres().values()):
            ser.processar(tempo_passado)


    def set_Fundo2(self):

        self.screen.blit(self.get_Background(),(0,0))
        for ser in list(self.get_Seres().values()):
            ser.desenhar(self.get_Screen())

    def __eq__(self,MiniMundo):

        return (self.get_Seres() == MiniMundo.get_Seres() and self.get_Ser_id() == MiniMundo.get_Ser_id()
        and self.get_Imagem() == MiniMundo.get_Imagem() and self.get_AREA() == MiniMundo.get_AREA()
        and self.get_Background() == MiniMundo.get_Background() and self.get_Screen() == MiniMundo.get_Screen())


class Ser(object):

    def __init__(self, mundo, nome, imagem, posicao = Vetor_2d(0.0,0.0),objetivo = Vetor_2d(0.0,0.0),
                 rdv = 0,Id = 0):

        self.mundo = mundo
        self.nome = nome
        self.imagem = imagem
        self.Ipygame = pygame.imagem.load(self.get_Imagem()).convert_alpha()
        self.posicao = posicao
        self.objetivo = objetivo
        self.velocidade = objetivo
        self.raio_de_visao = rdv # no futuro criar uma tabela que avalie o raio de visão de determinado seres em determinados mundos
        self.cerebro = MaquinaEstado() # no futuro não será somente maquinas de estado, no futuro estar no str
        self.id = Id
        #Colocar cerebro = MaquinaEstado
    def get_Mundo(self):
        
        return self.mundo

    def get_Nome(self):
        
        return self.nome
    
    def get_Imagem(self):
        
        return self.imagem

    def get_Posicao(self):
        
        return self.posicao

    def get_Objetivo(self):
        
        return self.objetivo

    def get_Velocidade(self):
        
        return self.velocidade
    
    def get_Id(self):
        
        return self.id

    def get_Ipygame(self):

        return self.Ipygame()

    def get_Cerebro(self):

        return self.cerebro

    def get_RV(self):

        return self.raio_de_visao
    
    def set_Mundo(self,mundo):
        
        self.mundo.set_Minimundo(mundo)

    def set_Nome(self,nome):
        
        self.nome = nome
    
    def set_Imagem(self,imagem):
        
        self.imagem = imagem

    def set_Posicao(self,posicao):
        
        self.posicao = posicao

    def set_Objetivo(self,objetivo):
        
        self.objetivo = objetivo

    def set_Velocidade(self,velocidade):
        
        self.velocidade = velocidade
    
    def set_Id(self,novoid):
        
        self.id = novoid

    def set_Ipygame(self,imagem):

        self.Ipymage = pygame.image.load(imagem).convert_alpha()

    def set_RV(self,novoRV):

        self.raio_de_visao = novoRV

    def set_Cerebro(self,novoCerebro):

        self.cerebro.set_Cerebro(novoCerebro)

    def set_Ser(self,Ser):

        if self.get_Mundo() != Ser.get_Mundo() and Ser.get_Mundo() != 0:  
            self.set_Mundo(Ser.get_Mundo())
            
        if self.get_Nome() != Ser.get_Nome() and Ser.get_Nome() != 0:  
            self.set_Nome(Ser.get_Nome())
            
        if self.get_Imagem() != Ser.get_Imagem and Ser.get_Imagem() != 0:
            self.set_Imagem(Ser.get_Imagem())

        if self.get_Posicao() != Ser.get_Posicao() and Ser.get_Posicao() != 0:  
            self.set_Posicao(Ser.get_Posicao())
            
        if self.get_Objetivo() != Ser.get_Objetivo() and Ser.get_Objetivo() != 0:  
            self.set_Objetivo(Ser.get_Objetivo())
            
        if self.get_Velociade() != Ser.get_Velociade() and Ser.get_Velocidade() != 0:  
            self.set_Velocidade(Ser.get_Velocidade())
            
        if self.get_Cerebro() != Ser.get_Cerebro() and Ser.get_Cerebro() != 0:  
            self.set_Cerebro(Ser.get_Cerebro())

        if self.get_Id() != Ser.get_Id() and Ser.get_Id() != 0:  
            self.set_Id(Ser.get_Id())

        if self.get_Ipygame() != Ser.get_Ipygame() and Ser.get_Ipygame() != 0:  
            self.set_Ipygame(Ser.get_Ipygame())

        if self.get_RV() != Ser.get_RV() and Ser.get_RV() != -1:
            self.set_RV(Ser.get_RV())

        if self.get_Cerebro() != Ser.get_Cerebro() and Ser.get_Cerebro() != 0:
            self.set_Cerebro(Ser.get_Cerebro())
    
    def desenhar(self,surface):

        x, y = self.get_Posicao()
        w, h = self.get_Ipygame().get_size()
        surface.blit(self.Ipygame(), (x-w/2, y-h/2))


    def processar(self,tempo_passado):

        self.get_Cerebro().pensar()

        if self.get_Velocidade() > 0 and self.get_Posicao() != self.get_Objetivo():

            vetor_destino = self.get_Objetivo() - self.get_Posicao()
            distancia_objetivo = vetor_destino.get_intensidade()
            vetor_direcao = Vetor_2d(*tuple(vetor_destino.unit().get_vetor()))
            distancia_movimento = min(distancia_objetivo, tempo_passado*self.get_Velocidade())
            self.set_Posicao(self.get_Posicao + vetor_direcao*distancia_movimento)

    
    def get_Visao_Mundo(self,nome):

        posicao = self.get_Posicao()
        for ser in list(self.seres.values()):
            if ser.nome == nome:
                distancia = posicao.get_link(posicao,ser.get_Posicao()).get_intensidade()
                if distancia < self.get_RV():
                    return ser

        return None

    def __str__(self):

        return ( " Nome: " + self.get_Nome() + " Imagem: " + self.get_Imagem() +" Posicao: "+ self.get_Posicao
                 + " Objetivo: " + self.get_Objetivo() +"Velocidade: " + self.get_Velocidade()
                 + "Raio de Visão: " + self.get_RV() + "Id: " + self.get_Id() + "Cérebro: " + self.get_Cerebro())

    def __eq__(self,Ser):

        return (self.get_Mundo() == Ser.get_Mundo , self.get_Nome() == Ser.get_Nome() ,self.get_Ipygame() == Ser.get_Ipygame()
                ,self.get_Posicao() == Ser.get_Posicao(), self.get_Objetivo() == Ser.get_Objetivo()
                ,self.get_Velocidade() == Ser.get_Velocidade(),self.get_Id() == Ser.get_Id()
                ,self.get_RV() == Ser.get_RV() , self.get_Cerebro() == Ser.get_Cerebro())


class Estado(object):

    def __init__(self,nome):

        self.nome = nome

    def get_Nome(self):

        return self.nome

    def agir(self):
        
        pass

    def verificar(self):
        
        pass

    def acao_entrada(self):
        
        pass

    def acao_saida(self):
        
        pass

    def __eq__(self):

        pass

class Central(Ser):

    def __init__(self,mundo,imagem,raio = 50.0):

        Ser.__init__(self,mundo,"Central",imagem)
        self.robos = {}
        self.estados_cerne = {"BG":BG,"IMP":IMP}
        self.cerebro.add_Estados(self.get_EC())
        self.raio_posto = raio
        #Colocar cerne = {"BG":BG, "IMP":IMP}
    def get_Cerebro(self):

        Ser.get_Cerebro(self)

    def get_Robos(self):

        return self.robos

    def get_Raio_Posto(self):

        return self.raio_posto

    def get_EC(self):

        return self.estados_cerne
    
    def set_Robos(self,NovosRobos):

        self.robos = NovosRobos

    def set_EC(self,EC):

        self.estados_cerne = EC
        self.cerebro.add_Estados(self.get_EC())

    def set_Raio_Posto(self,raio_posto):

        self.raio_posto = raio_posto


    def add_EC(self,estado):

        self.estados_cerne[estado.nome] = estado
        self.cerebro.add_Estados(self.get_EC())

    def remove_EC(self,estado_nome):

        del self.estados_cerne[estado_nome]
        self.cerebro.add_Estados(self.get_EC())

    def set_Ser(self,Central):

        Ser.set_Ser(self,Central)

        if self.get_Robos() != Ser.get_Robos() and Ser.get_Robos() != 0:
            self.set_Robos(Ser.get_Robos())

        if self.get_EC() != Ser.get_EC() and Ser.get_EC() != 0:
            self.set_EC(Ser.get_EC())

        if self.get_Raio_Posto() != Ser.get_Raio_Posto() and Ser.get_Raio_Posto() != 0:
            self.set_Raio_Posto(Ser.get_Raio_Posto())

        
    def __str__(self):

        Ser.__str__(self)

    def __eq__(self,Central):

        return (Ser.__eq__(self,Central) and self.get_Robos() == Central.get_Robos() and self.get_EC() == Central.get_EC()
                and self.get_Raio_Posto() == Central.get_Raio_Posto())



    def desenhar(self,surface):

        Ser.desenhar(self,surface)
        pygame.draw.circle(surface,(200, 255, 200),self.get_Posicao(),self.get_Raio_Posto())


#No futuro irei desenvolver a classe Viagem Planar onde será possível
#mudar um ser para outro mundo, será preciso criar a classe Gerenciador
#de Mundos, que vai ter um dircionario de mundos indexados por ID,
#para mudar de mundo será preciso apenas mudar o ID(eu acho), será possivel
#influir em outro mundo remotamente(mudança na classe Ser, novo método: Viagem Planar, mudança em Set_Ser,
#Criar nova classe,dar o atributo ID_mundo a classe mundo,criar a classe Gerenciador de Mundos(dicionario de mundos),
#Interface para um ser influir em outros mundos)'''

        
        
        
