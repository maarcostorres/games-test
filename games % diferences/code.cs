using System;
using System.Collections.Generic;

class Jogo
{
    public string Nome { get; set; }
    public int JogadoresAtivos { get; set; }
}

class Program
{
    static void Main(string[] args)
    {
        List<Jogo> jogos = new List<Jogo>
        {
            new Jogo { Nome = "Fortnite", JogadoresAtivos = new Random().Next(1000000, 5000000) },
            new Jogo { Nome = "Minecraft", JogadoresAtivos = new Random().Next(500000, 1000000) },
            new Jogo { Nome = "League of Legends", JogadoresAtivos = new Random().Next(500000, 1000000) },
            new Jogo { Nome = "Valorant", JogadoresAtivos = new Random().Next(100000, 500000) },
            new Jogo { Nome = "Among Us", JogadoresAtivos = new Random().Next(100000, 500000) }
        };

        // Classificar os jogos pelo número de jogadores ativos
        jogos.Sort((jogo1, jogo2) => jogo2.JogadoresAtivos.CompareTo(jogo1.JogadoresAtivos));

        // Calcular a porcentagem total de jogadores ativos
        int totalJogadores = 0;
        foreach (var jogo in jogos)
        {
            totalJogadores += jogo.JogadoresAtivos;
        }

        // Exibir classificação e porcentagem de jogadores ativos
        Console.WriteLine("Classificação dos jogos mais jogados:");
        for (int i = 0; i < jogos.Count; i++)
        {
            double porcentagemAtivos = (jogos[i].JogadoresAtivos / (double)totalJogadores) * 100;
            Console.WriteLine($"{i + 1}. {jogos[i].Nome}: {porcentagemAtivos:F2}% de jogadores ativos");
        }
    }
}
