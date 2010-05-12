package org.kohsuke.args4j;

import java.io.File;
import java.lang.annotation.Retention;
import java.lang.annotation.Target;
import java.lang.reflect.AccessibleObject;
import java.util.ResourceBundle;

import static java.lang.annotation.ElementType.FIELD;
import static java.lang.annotation.ElementType.METHOD;
import static java.lang.annotation.RetentionPolicy.RUNTIME;

/**
 * Marks a field/setter that receives a command line switch value.
 *
 * <p>
 * This annotation can be placed on a field of type T or the method
 * of the form <tt>void <i>methodName</i>(T value)</tt>. Its access
 * modified can be anything, but if it's not public, your application
 * needs to run in a security context that allows args4j to access
 * the field/method (see {@link AccessibleObject#setAccessible(boolean)}.
 *
 * <p>
 * The behavior of the annotation differs depending on T --- the type
 * of the field or the parameter of the method.
 *
 * <h2>Boolean Switch</h2>
 * <p>
 * When T is boolean , it represents
 * a boolean option that takes the form of "-OPT". When this option is set,
 * the property will be set to true.
 *
 * <h2>String Switch</h2>
 * <p>
 * When T is {@link String}, it represents
 * an option that takes one operand. The value of the operand is set
 * to the property.
 *
 * <h2>Enum Switch</h2>
 * <p>
 * When T is derived from {@link Enum}, it represents an option that takes
 * an operand, which must be one of the enum constant. The comparion between
 * the operand and the enum constant name is done in a case insensitive fashion.
 * <p>
 * For example, the following definition will represent command line options
 * like "-coin penny" or "-coin DIME" but things like "-coin" or "-coin abc" are
 * errors.
 *
 * <pre>
 * enum Coin { PENNY,NICKEL,DIME,QUARTER }
 *
 * class Option {
 *   &#64;Option(name="-coin")
 *   public Coin coin;
 * }
 * </pre>
 *
 * <h2>File Switch</h2>
 * <p>
 * When T is a {@link File}, it represents an option that takes a file/directory
 * name as an operand.
 *
 * @author Kohsuke Kawaguchi
 */
@Retention(RUNTIME)
@Target({FIELD,METHOD})
public @interface Option {
    /**
     * Name of the option, such as "-foo" or "-bar".
     */
    String name();

    /**
     * Help string used to display the usage screen.
     *
     * <p>
     * This parameter works in two ways. For a simple use,
     * you can just encode the human-readable help string directly,
     * and that will be used as the message. This is easier,
     * but it doesn't support localization.
     *
     * <p>
     * For more advanced use, this property is set to a key of a
     * {@link ResourceBundle}. The actual message is obtained
     * by querying a {@link ResourceBundle} instance supplied to
     * {@link CmdLineParser} by this key. This allows the usage
     * screen to be properly localized.
     *
     * <p>
     * If this value is empty, the option will not be displayed
     * in the usage screen.
     */
    String usage() default "";

    /**
     * When the option takes an operand, the usage screen will show something like this:
     * <pre>
     * -x FOO  : blah blah blah
     * </pre>
     * You can replace the 'FOO' token by using this parameter.
     *
     * <p>
     * If left unspecifiied, this value is infered from the type of the option.
     *
     * <p>
     * Just like {@link #usage()}, normally, this value is printed as is.
     * But if a {@link ResourceBundle} is given to the {@link CmdLineParser},
     * it will be used to obtain the locale-specific value.
     */
    String metaVar() default "";
}
