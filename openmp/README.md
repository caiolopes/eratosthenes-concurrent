# Implementação com OpenMP

Nesse trabalho foi implementado o algoritmo Crivo de Eratóstenes, este utilizado para encontrar números primos até um limite N definido pelo usuário como um argumento passado ao programa. Foram implementadas uma versão sequencial, uma versão paralelizada por controle e uma paralelizada por dados utilizando OpenMP.

## Grupo
- Caio de Sá Lopes
- Bruno Cepeda Henriques
- Guilherme Andriotti Momesso

## Resultados

Nesse trabalho foi implementado o algoritmo Crivo de Eratóstenes, este utilizado para encontrar números primos até um limite N definido pelo usuário como um argumento passado ao programa.

Na nossa análise, consideramos dois tamanhos para N: 5 milhões e 500 milhões.
Para as versões paralelizadas, utilizamos 2, 4 e 8 threads.

|            	| Threads 	| N             	| SpeedUp 	| Eficiência 	| Tempo 	|
|------------	|---------	|---------------	|---------	|------------	|-------	|
| Sequencial 	| -       	| 5.000.000      	|     -     |     -         | 0.06513   |
| Sequencial 	| -       	| 500.000.000 	    |    -      |    -          | 9.26095	|
| Dados      	| 2       	| 5.000.000      	| 1.55396 | 0.77698       | 0.04191 |
| Dados      	| 2       	| 500.000.000 	    | 1.42800 | 0.71400       | 13.2073 |
| Dados      	| 4       	| 5.000.000      	| 1.90702 | 0.47675       | 0.03301	|
| Dados      	| 4       	| 500.000.000 	    | 1.49412 | 0.37353       | 16.03930|
| Dados      	| 8       	| 5.000.000      	| 1.54544 | 0.19318       | 0.04162	|
| Dados      	| 8       	| 500.000.000 	    | 1.47626 | 0.18453       | 24.73003|
| Controle   	| 2       	| 5.000.000      	| 1.67219 | 0.83609       | 0.03895	|
| Controle   	| 2       	| 500.000.000 	    | 1.60044 | 0.80022       | 4.71559	|
| Controle   	| 4       	| 5.000.000      	| 2.26366 | 0.56591       | 0.02781	|
| Controle   	| 4       	| 500.000.000 	    | 1.75895 | 0.43973       | 4.10346	|
| Controle   	| 8       	| 5.000.000      	| 2.21799 | 0.27724       | 0.02900	|
| Controle   	| 8       	| 500.000.000 	    | 1.58863 | 0.19857       | 4.20142|

Tabela 1: Diferentes desempenhos

## Análise dos resultados

Todos os experimentos foram executados em uma máquina com 4 núcleos e para efeitos de comparação, foi variado o número de threads ao invés do número de núcleos. Para cada experimento da tabela acima foram realizadas 100 execuções dos algoritmos e realizada a média aritimética dos valores de tempo de execução. O tempo de execução está em segundos e os testes foram realizados utilizando um script em bash que retorna o valor acumulado das médias.

Pode-se notar que a abordagem sequencial foi a com menor desempenho visto que todos os speedups das abordagens paralelas foram maiores que 1. Diferentemente das implementações em pthreads, o paralelismo por dados obteve um maior SpeedUp, deixando de ser o pior desempenho entre as três abordagens. Ainda assim, o modelo por controle foi o que forneceu melhores resultados e desemplenho.

O modelo de paralelismo por controle apresentou baixa escalabilidade, já que em um contexto de workpool pelo qual o algoritmo funciona, um grande número de trabalhadores não significa diretamente uma maior performance computacional. No caso, a thread com maior número de cálculos a executar são as de menor valor (cálculo do  crivo para os números 2, 3, 5, etc.), já que possuem o maior número de múltiplos. Para esse algoritmo, os valores com maior eficiêcia são de 2 a 4 threads.

Ainda mais, esses códigos poderiam possuir um valor ainda mais alto de speedup e eficiêcia caso fosse utilizado o algoritmo de cálculo impar, onde desde o início do código já se elimina quaisquer valores pares do vetor, poupando o algoritmo de verificar se múltiplos de 2 são primos, o que no caso conta por metade da memória e dos cálculos executados.

## Conclusão

Apesar do algoritmo do crivo de eratosthenes ser eficiênte em sua forma sequêncial, sua paralelização é de difícil modelagem e não apresenta grandes valores de eficiência ou speedup para modelos de paralelização explícita, mas possui bom desempenho em seu modelo OpenMP e fácil implementação comparado ao modelo de implementação por manipulação de threads.
