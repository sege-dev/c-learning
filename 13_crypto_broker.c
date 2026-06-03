#include <stdio.h>
float gettlamount();
float usdrate();
float btcprice();
float usdconverter(float tlamount, float usdrate);
float btcconverter(float usdamount, float btcprice);
int main()
{
    float tl, btcr, usdr, usd, btc;
    printf("!!!Welcome to BTC calculator!!!");
    tl = gettlamount();
    usdr = usdrate();
    btcr = btcprice();
    usd = usdconverter(tl, usdr);
    btc = btcconverter(usd, btcr);
    printf("\nYou have %.2f dollar and it can buy %.4f BTC", usd, btc);
    return 0;
}
float gettlamount()
{
    float tlamount;
    do
    {
        printf("\nplease enter total TL: ");
        scanf("%f", &tlamount);
    } while (tlamount <= 0);
    return tlamount;
}
float usdrate()
{
    float usdrate;
    do
    {
        printf("\nplease enter the usd rate: ");
        scanf("%f", &usdrate);
    } while (usdrate <= 0);
    return usdrate;
}
float usdconverter(float tlamount, float usdrate)
{
    return tlamount / usdrate;
}
float btcconverter(float usdamount, float btcprice)
{
    return usdamount / btcprice;
}
float btcprice()
{
    float btcprice;
    do
    {
        printf("\n enter BTC price: ");
        scanf("%f", &btcprice);
    } while (btcprice <= 0);
    return btcprice;
}