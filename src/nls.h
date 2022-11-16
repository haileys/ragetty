// GNU GPL. See util-linux COPYING for license.

#ifndef UTIL_LINUX_NLS_H
#define UTIL_LINUX_NLS_H

#ifndef LOCALEDIR
#define LOCALEDIR "/usr/share/locale"
#endif

# include <locale.h>


#ifdef ENABLE_NLS
# include <libintl.h>
/*
 * For NLS support in the public shared libraries we have to specify text
 * domain name to be independent on the main program. For this purpose define
 * UL_TEXTDOMAIN_EXPLICIT before you include nls.h to your shared library code.
 */
# ifdef UL_TEXTDOMAIN_EXPLICIT
#  define _(Text) dgettext (UL_TEXTDOMAIN_EXPLICIT, Text)
# else
#  define _(Text) gettext (Text)
# endif
# ifdef gettext_noop
#  define N_(String) gettext_noop (String)
# else
#  define N_(String) (String)
# endif
# define P_(Singular, Plural, n) ngettext (Singular, Plural, n)
#else
# undef bindtextdomain
# define bindtextdomain(Domain, Directory) /* empty */
# undef textdomain
# define textdomain(Domain) /* empty */
# define _(Text) (Text)
# define N_(Text) (Text)
# define P_(Singular, Plural, n) ((n) == 1 ? (Singular) : (Plural))
#endif /* ENABLE_NLS */

# include <langinfo.h>

#endif /* UTIL_LINUX_NLS_H */
