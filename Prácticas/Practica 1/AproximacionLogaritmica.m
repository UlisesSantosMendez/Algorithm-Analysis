%%VALORES DE X
x = [ 10 100 200 300 400 500 600 1000];
%%VALORES DE y = F(x) en Milisegundos
y = [ 100.12 200.25 230.56 247.25 260.254 269.984 277.23 300.02];

%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
p = polyfit(log(x),y,1)
a=p(1);
c=p(2);
fprintf('f(x)=%f*ln(x)+%f\n',a,c);

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
xi=linspace(0,1000,2000);      %%ESPACIO DE PUNTOS PARA Xi
z = polyval(p,log(xi));        %%EVALUACION DE LA CURVA LOGARITMICA P EN EL ESPACIO Xi

%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
plot(x,y,'o',xi,z,'-'),grid;
ylabel('F(x)');
xlabel('x');
title('Ajuste logarítmico y=a·ln(x)+c');

