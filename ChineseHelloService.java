package com.example.demo;

import org.springframework.stereotype.Service;

@Service
public class ChineseHelloService implements IHelloServiceInterface{

    @Override
    public String hello() {
        System.out.println("你好");
        return "你好, Spring Boot!";
    }
}
