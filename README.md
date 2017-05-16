# Sobre esses códigos

Nesse trabalho foi implementado o algoritmo Crivo de Eratóstenes, este utilizado para encontrar números primos até um limite N definido pelo usuário como um argumento passado ao programa. Foram implementadas uma versão sequencial, uma versão paralelizada por controle e uma paralelizada por dados.

## Grupo
- Caio de Sá Lopes
- Bruno Cepeda
- Guilherme Momesso

## Resultados

Nesse trabalho foi implementado o algoritmo Crivo de Eratóstenes, este utilizado para encontrar números primos até um limite N definido pelo usuário como um argumento passado ao programa.

|            	| Threads 	| N             	| SpeedUp 	| Eficiência 	| Tempo 	|
|------------	|---------	|---------------	|---------	|------------	|-------	|
| Sequencial 	| -       	| 100.000       	|         	|            	|       	|
| Sequencial 	| -       	| 1.000.000.000 	|         	|            	|       	|
| Dados      	| 2       	| 100.000       	|         	|            	|       	|
| Dados      	| 2       	| 1.000.000.000 	|         	|            	|       	|
| Dados      	| 4       	| 100.000       	|         	|            	|       	|
| Dados      	| 4       	| 1.000.000.000 	|         	|            	|       	|
| Dados      	| 8       	| 100.000       	|         	|            	|       	|
| Dados      	| 8       	| 1.000.000.000 	|         	|            	|       	|
| Controle   	| 2       	| 100.000       	|         	|            	|       	|
| Controle   	| 2       	| 1.000.000.000 	|         	|            	|       	|
| Controle   	| 4       	| 100.000       	|         	|            	|       	|
| Controle   	| 4       	| 1.000.000.000 	|         	|            	|       	|
| Controle   	| 8       	| 100.000       	|         	|            	|       	|
| Controle   	| 8       	| 1.000.000.000 	|         	|            	|       	|

Tabela 1: Diferentes desempenhos