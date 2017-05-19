# Sobre esses códigos

Nesse trabalho foi implementado o algoritmo Crivo de Eratóstenes, este utilizado para encontrar números primos até um limite N definido pelo usuário como um argumento passado ao programa. Foram implementadas uma versão sequencial, uma versão paralelizada por controle e uma paralelizada por dados utilizando OpenMP.

## Grupo
- Caio de Sá Lopes
- Bruno Cepeda
- Guilherme Momesso

## Resultados

Nesse trabalho foi implementado o algoritmo Crivo de Eratóstenes, este utilizado para encontrar números primos até um limite N definido pelo usuário como um argumento passado ao programa.

Na nossa análise, consideramos dois tamanhos para N: 5 milhões e 500 milhões.
Para as versões paralelizadas, utilizamos 2, 4 e 8 threads.

|            	| Threads 	| N             	| SpeedUp 	| Eficiência 	| Tempo 	|
|------------	|---------	|---------------	|---------	|------------	|-------	|
| Sequencial 	| -       	| 5.000.000      	|     -     |     -    | 0.05899|
| Sequencial 	| -       	| 500.000.000 	  |    -     |    -     | 9.05822	|
| Dados      	| 2       	| 5.000.000      	| 0.577201  | 0.286005 | 0.10220|
| Dados      	| 2       	| 500.000.000 	  | 0.685849 | 0.342924 | 13.2073 	|
| Dados      	| 4       	| 5.000.000      	| 0.503757 | 0.125939 | 0.11710	|
| Dados      	| 4       	| 500.000.000 	  | 0.564751 | 0.141187 | 16.03930 	|
| Dados      	| 8       	| 5.000.000      	| 0.409254 | 0.051156 | 0.14414	|
| Dados      	| 8       	| 500.000.000 	  | 0.366729 | 0.045841 | 24.730038	|
| Controle   	| 2       	| 5.000.000      	| 1.836550 | 0.918275 | 0.03212	|
| Controle   	| 2       	| 500.000.000 	  | 1.920909 | 0.960454 | 4.71559	|
| Controle   	| 4       	| 5.000.000      	| 2.714680 | 0.67867 | 0.02173	|
| Controle   	| 4       	| 500.000.000 	  | 2.207459 | 0.551864 | 4.10346	|
| Controle   	| 8       	| 5.000.000      	| 3.146133 | 0.393266 | 0.01875	|
| Controle   	| 8       	| 500.000.000 	  | 2.155988 | 0.269498 | 4.201423	|

Tabela 1: Diferentes desempenhos

## Análise dos resultados

Todos os experimentos foram executados em uma máquina com 8 núcleos e para efeitos de comparação, foi variado o número de threads ao invés do número de núcleos. Para cada experimento da tabela acima foram realizadas 100 execuções dos algoritmos e realizada a média aritimética dos valores de tempo de execução. O tempo de execução está em segundos e os testes foram realizados utilizando um script em bash que retorna o valor acumulado das médias.

Pode-se notar que o speedup e a eficiêcia do modelo de paralelismo de dados por blocos (onde cada thread recebe um "pedaço" no vetor total) é o modelo com menos eficiência, sendo pior que o algoritmo sequencial. Isso se deve ao fato de que para sua execução, cada thread repete os mesmos cálculos do crivo, e como os índices variam de bloco para bloco, sendo o limite o número final do bloco, os primeiros blocos não possuem muitos cálculos, onde os últimos blocos executarão quase o crivo inteiro, dado que estão no final do vetor.

O modelo de paralelismo por controle entretanto, apresentou valores de speedup bem satisfatórios, mas baixa escalabilidade, já que em um contexto de workpool pelo qual o algoritmo funciona, um grande número de trabalhadores não significa diretamente uma maior performance computacional. No caso, a thread com maior número de cálculos a executar são as de menor valor (cálculo do  crivo para os números 2, 3, 5, etc.), já que possuem o maior número de múltiplos. Para esse algoritmo, os valores com maior eficiêcia são de 2 a 4 threads.

Ainda mais, esses códigos poderiam possuir um valor ainda mais alto de speedup e eficiêcia caso fosse utilizado o algoritmo de cálculo impar, onde desde o início do código já se elimina quaisquer valores pares do vetor, poupando o algoritmo de verificar se múltiplos de 2 são primos, o que no caso conta por metade da memória e dos cálculos executados.

## Conclusão

Apesar do algoritmo do crivo de eratosthenes ser eficiênte em sua forma sequêncial, sua paralelização é de difícil modelagem e não apresenta grandes valores de eficiência ou speedup.
