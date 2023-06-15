import random

class Jogo:
    def __init__(self, nome, jogadores_ativos):
        self.nome = nome
        self.jogadores_ativos = jogadores_ativos

# Dados fictícios de jogos
jogos = [
    Jogo("Fortnite", random.randint(1000000, 5000000)),
    Jogo("Minecraft", random.randint(500000, 1000000)),
    Jogo("League of Legends", random.randint(500000, 1000000)),
    Jogo("Valorant", random.randint(100000, 500000)),
    Jogo("Among Us", random.randint(100000, 500000)),
]

# Classificar os jogos pelo número de jogadores ativos
jogos_classificados = sorted(jogos, key=lambda jogo: jogo.jogadores_ativos, reverse=True)

# Imprimir classificação e porcentagem de jogadores ativos
for i, jogo in enumerate(jogos_classificados):
    porcentagem_ativos = (jogo.jogadores_ativos / sum([jogo.jogadores_ativos for jogo in jogos])) * 100
    print(f"{i+1}. {jogo.nome}: {porcentagem_ativos:.2f}% de jogadores ativos")
