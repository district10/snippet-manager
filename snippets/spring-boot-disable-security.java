// yml: security.ignored=/**
@SpringBootApplication(exclude = org.springframework.boot.autoconfigure.security.SecurityAutoConfiguration.class)

// comment out this line
@EnableWebSecurity
public class MultiHttpSecurityConfig {

    @Autowired
    private CustomAuthenticationProvider customAuthenticationProvider;

    @Autowired
    public void configureGlobal(AuthenticationManagerBuilder auth) {
        auth.authenticationProvider(customAuthenticationProvider);
    }

    @Configuration
    public static class CustomWebSecurityConfigurerAdapter extends WebSecurityConfigurerAdapter {

        @Autowired
        private CustomAuthenticationFilter customAuthenticationFilter;

        @Override
        protected void configure(HttpSecurity http) throws Exception {
            http.sessionManagement().disable();
            http.securityContext().disable();
            http.requestCache().requestCache(new NullRequestCache());
            http.addFilter(customAuthenticationFilter);
            http
                    .csrf().disable()
                    .authorizeRequests()
                    .antMatchers(HttpMethod.OPTIONS, "/**").denyAll()
                    .antMatchers("/**/ratings/**").permitAll()
                    .antMatchers("/**/css/**").permitAll()
                    .antMatchers("/**/images/**").permitAll()
                    .antMatchers("/**/fonts/**").permitAll()
                    .antMatchers("/**/js/**").permitAll()
                    .antMatchers(HttpMethod.GET, "/health").permitAll()
                    .anyRequest().authenticated();
        }
    }
}
