int func(n)
{
if(n == 0)
return 0;

return(n + func(n-l));
}

/*RESPOSTA: Essa função recursiva soma o numero da variável 'n' com todos os números abaixo dele até o zero.*/
