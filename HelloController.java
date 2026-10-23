package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

@Controller
public class HelloController {

    @Autowired
    @Qualifier("englishHelloService")
    private IHelloServiceInterface helloService;

    @GetMapping("/hello")
    @ResponseBody
    public String Hello() {
        return helloService.hello();
    }
}
