package mol;


import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.lang.annotation.Inherited;
import mol.mshtml.IHTMLElement;

@Retention(RetentionPolicy.RUNTIME)
@Target({ElementType.METHOD})
@Inherited

public @interface DOMEvent {
	String value();
	Class<?> type() default IHTMLElement.class;
}
