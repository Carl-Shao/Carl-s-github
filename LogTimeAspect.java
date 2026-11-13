package com.example.demo.aop;


import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.springframework.stereotype.Component;

@Aspect
@Component
public class LogTimeAspect {

    @Around("@annotation(com.example.demo.annotation.LogTime)")
    public Object logTime(ProceedingJoinPoint proceedingJoinPoint) throws Throwable {
        long start = System.currentTimeMillis();
        Object result = proceedingJoinPoint.proceed();
        System.out.println(proceedingJoinPoint.getSignature().toShortString() +
                "Time: " + (System.currentTimeMillis() - start) + "ms");
        return result;
    }
}
