package com.example.demo;

import org.springframework.stereotype.Service;

@Service
public class EnglishHelloService implements IHelloServiceInterface{

    @Override
    public String hello() {
        System.out.println("hello");
        return "hello, Spring Boot!";
    }
}
