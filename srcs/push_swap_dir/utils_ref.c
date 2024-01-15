/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ref.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:20:00 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/12 14:21:44 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/swaplib.h"

t_ref	mid_sup(t_ref ref)
{
	t_ref	sup;

	sup = ref;
	sup.start_taff = ref.ind_mid;
	sup.non_taff = sup.end_taff - sup.start_taff;
	sup.ind_mid = sup.start_taff + sup.non_taff / 2;
	return (sup);
}

t_ref	mid_low(t_ref ref)
{
	t_ref	low;

	low = ref;
	low.end_taff = ref.ind_mid;
	low.non_taff = ref.ind_mid - ref.start_taff;
	low.ind_mid = low.start_taff + low.non_taff / 2;
	return (low);
}

t_ref	mid_supsup(t_ref ref)
{
	t_ref	refsupsup;

	refsupsup = ref;
	refsupsup.start_taff = ref.ind_mid + ((ref.end_taff - ref.ind_mid) / 2);
	refsupsup.non_taff = ref.end_taff - refsupsup.start_taff;
	refsupsup.ind_mid = refsupsup.start_taff + (refsupsup.non_taff / 2);
	refsupsup.end_taff = ref.end_taff;
	return (refsupsup);
}

t_ref	mid_suplow(t_ref ref)
{
	t_ref	refsuplow;

	refsuplow = ref;
	refsuplow.start_taff = ref.ind_mid;
	refsuplow.end_taff = (ref.ind_mid) + ((ref.end_taff - ref.ind_mid) / 2);
	refsuplow.non_taff = refsuplow.end_taff - refsuplow.start_taff;
	refsuplow.ind_mid = refsuplow.start_taff + (refsuplow.non_taff / 2);
	return (refsuplow);
}

t_ref	mid_lower(t_ref ref)
{
	t_ref	reflow;

	reflow = ref;
	reflow.end_taff = ref.ind_mid;
	reflow.non_taff = ref.ind_mid - ref.start_taff;
	reflow.ind_mid = ref.start_taff + (ref.ind_mid - ref.start_taff) / 2;
	reflow.start_taff = ref.start_taff;
	return (reflow);
}
