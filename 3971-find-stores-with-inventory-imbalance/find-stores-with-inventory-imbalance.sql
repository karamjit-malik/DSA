# Write your MySQL query statement below

with t1 as(
    select store_id, max(price) as pmost_exp_product, min(price) as pcheapest_product
    from inventory group by store_id
),
t2 as(
    select o.store_id, o.pmost_exp_product, o.pcheapest_product,
    (
        select i.quantity from inventory as i
        where i.store_id = o.store_id and i.price = o.pcheapest_product
    )/(
        select i.quantity from inventory as i
        where i.store_id = o.store_id and i.price = o.pmost_exp_product
    ) as imbalance_ratio
    from t1 as o
)
select a.store_id, b.store_name, b.location, (select x.product_name from inventory as x where x.store_id = a.store_id and a.pmost_exp_product = x.price) as most_exp_product,(select x.product_name from inventory as x where x.store_id = a.store_id and a.pcheapest_product = x.price) as cheapest_product, round(a.imbalance_ratio,2) as imbalance_ratio
from t2 as a join stores as b on a.store_id = b.store_id
where (
    select count(distinct i.inventory_id) from inventory as i
    where i.store_id = a.store_id
) >= 3 and imbalance_ratio > 1
order by a.imbalance_ratio desc, b.store_name;