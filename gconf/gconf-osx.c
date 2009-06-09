#include <stdlib.h>
#include <glib.h>

static char *locale_dir;
static char *conf_dir;
static char *etc_dir;
static char *server_dir;
static char *backend_dir;
static char *env;

const char *
replace_prefix (const char *original, char **container)
{
	if (*container)
		return *container;
	
	if (!env)
		env = getenv ("GCONF_PREFIX");
	
	if (env && *env && g_str_has_prefix (original, PREFIX))
	{
		*container = g_build_filename (env,
			                       original + strlen(PREFIX) + 1,
					       NULL);
	}
	else
	{
		*container = g_strdup (original);
	}

	return *container;
}

const char *
_gconf_osx_get_locale_dir (void)
{
	return replace_prefix (GCONF_LOCALE_DIR, &locale_dir);
}

const char *
_gconf_osx_get_confdir (void)
{
	return replace_prefix (GCONF_CONFDIR, &conf_dir);	
}

const char *
_gconf_osx_get_etcdir ()
{
	return replace_prefix (GCONF_ETCDIR, &etc_dir);
}

const char *
_gconf_osx_get_serverdir ()
{
	return replace_prefix (GCONF_SERVERDIR, &server_dir);
}

const char *
_gconf_osx_get_backend_dir ()
{
	return replace_prefix (GCONF_BACKEND_DIR, &backend_dir);
}
