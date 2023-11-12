import pygame, random

pygame.init()

clock = pygame.time.Clock()
run = True
#tela
tela_altura = 500
tela_largura = 500
tela = pygame.display.set_mode((tela_largura, tela_altura))
#imagens
#MODIFICAÇÃO: coloquei as imagens dentro de um arquivo para ficar mais organizado
# o './'diz para o programa começar a procurar a imagem no mesmo arquivo que está o nosso programa
# e depois o 'imagens/' diz para entrar na pasta imagens e pegar a imagem que queremos
fundo = pygame.image.load("./imagens/teste.png")
sprite = pygame.image.load("./imagens/sprite.png")
obstaculos = pygame.image.load("./imagens/obstaculos.png")
#player
x = 50
y = 50
vel = 5
#obstaculos
obsX = 500
obsY=random.randint(0,500)
obsVel = 8
#UI
colidiu = False
pontos = 0
#Pontos
# aqui estamos primeiro especificando uma fonte para desenhar na tela
font = pygame.font.Font("freesansbold.ttf", 32)
# definimos a string que queremos e a cor dela para o pygame usar depois
pontuacao = font.render("Pontos: "+str(pontos), True, (255,255,255))
Morte = font.render("Morreu!", True, (255,255,255))

#LOOP DO JOGO
while run:
    #tartaruga e obstaculos
        #movimento do obstaculo
    if not colidiu:
        if obsX <= 0-75:
            obsX = 500
            obsY = random.randint(50,400)
            pontos = pontos+1
        else:
            obsX = obsX - obsVel

            #movimento
        if colidiu == False:
            key = pygame.key.get_pressed()
            if key[pygame.K_a] == True:
                x = x-vel
            if key[pygame.K_d] == True:
                x = x+vel
            if key[pygame.K_w] == True:
                y = y-vel
            if key[pygame.K_s] == True:
                y = y+vel
        #atualizar movimento para a tartaruga e os obstaculos
    tartaruga = (x,y,50,50)
    obstaculo = (obsX,obsY,75,75)

    #colocar os sprites na tela
    tela.blit(fundo,(0,0))
    tela.blit(sprite,(x,y))
    tela.blit(obstaculos,(obsX,obsY))

    #pontuação
    pontuacao = font.render("Pontuação: "+str(pontos), True, (255,255,255))#atualiza a string pontuação 
    tela.blit(pontuacao, (10,10))#escreve a pontuação na tela na posicão 10,10
    #Gameover
    # segue a mesma lógica da pontuação, mas só aparece quando tivermos batido num obstaculo
    if colidiu == True: #quando verdadeiro faz aparecer na tela um texto de fim de jogo
        tela.blit(Morte, (250,250))

    #colisões
    # Basicamente, o 1º IF verifica se um dos lados extremos da tartaruga está
    # entre os lados extremos do obstaculo no eixo X
    # 
    # o 2º IF faz a mesma coisa mas no eixo Y
    # 
    # se as duas condiçoes forem verdadeiras, logo a tartaruga colidiu
    # 
    # sempre fazemos isso para o menor objeto, porque existe um caso em que,
    # se o jogador for maior que o objeto, ele pode acabar atravesando o obstaculo sem que as condições sejam satisfeitas
    # se no nosso jogo existisse obstaculos de variados tamanhos, a verificação teria mais IFs para vericar cada caso
    if (x >= obsX and x <= obsX+75) or (x+50 >= obsX and x+50 <= obsX+75):
        if  (y >= obsY and y <= obsY+75) or (y+50 >= obsY and y+50 <= obsY+75):
            colidiu = True

    # a parte que faz a janela 'rodar' corretamente
    #  
    #atualizar
    pygame.display.flip()
    clock.tick(60)

    #fechar o jogo
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False