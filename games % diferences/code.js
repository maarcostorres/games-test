class Jogo {
    constructor(nome, jogadoresAtivos) {
        this.nome = nome;
        this.jogadoresAtivos = jogadoresAtivos;
    }
}

// Dados fictícios de jogos
const jogos = [
    new Jogo("Fortnite", getRandomNumber(1000000, 5000000)),
    new Jogo("Minecraft", getRandomNumber(500000, 1000000)),
    new Jogo("League of Legends", getRandomNumber(500000, 1000000)),
    new Jogo("Valorant", getRandomNumber(100000, 500000)),
    new Jogo("Among Us", getRandomNumber(100000, 500000))
];

// Classificar os jogos pelo número de jogadores ativos
jogos.sort((jogo1, jogo2) => jogo2.jogadoresAtivos - jogo1.jogadoresAtivos);

// Calcular a porcentagem total de jogadores ativos
const totalJogadores = jogos.reduce((total, jogo) => total + jogo.jogadoresAtivos, 0);

// Exibir classificação e porcentagem de jogadores ativos
console.log("Classificação dos jogos mais jogados:");
jogos.forEach((jogo, index) => {
    const porcentagemAtivos = (jogo.jogadoresAtivos / totalJogadores) * 100;
    console.log(`${index + 1}. ${jogo.nome}: ${porcentagemAtivos.toFixed(2)}% de jogadores ativos`);
});

// Função auxiliar para obter um número aleatório dentro de um intervalo
function getRandomNumber(min, max) {
    return Math.floor(Math.random() * (max - min + 1) + min);
}
