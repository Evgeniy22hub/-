
# scrapy runspider --set FEED_EXPORT_ENCODING=utf-8  main.py -o output.json
import scrapy

class ExampleSpider(scrapy.Spider):
    name = 'example'
    allowed_domains = ['nixdn.ru']
    start_urls = ['https://nixdn.ru/']

    def parse(self, response):
        #link = response.css('a.item::attr(href)')
        for link in response.css("div.product-thumb.transition div.image a::attr(href)").getall():
            yield response.follow(link, callback=self.parse_page)


    def parse_page(self, response):
        
        yield {
            "title": response.css('h1.heading span::text').get(),
            "price": response.css("span.autocalc-product-price::text").get(),
            "info": response.css("#tab-description::text").get(),
            "link": response.request.url
        }