-- 코드를 입력하세요
SELECT
    YEAR(O.SALES_DATE) AS YEAR, MONTH(SALES_DATE) AS MONTH, COUNT(DISTINCT USER_ID) AS PUCHASED_USERS, ROUND((COUNT(DISTINCT USER_ID)/(SELECT COUNT(*) FROM USER_INFO WHERE USER_INFO.JOINED LIKE '2021%')), 1) AS PUCHASED_RATIO
FROM
    USER_INFO AS U
    JOIN ONLINE_SALE AS O USING(USER_ID)
WHERE
    U.JOINED LIKE '2021%'
GROUP BY
    EXTRACT(YEAR FROM O.SALES_DATE), MONTH(O.SALES_DATE)
ORDER BY
    YEAR(O.SALES_DATE), MONTH(O.SALES_DATE);

# SELECT *
# FROM USER_INFO
#     JOIN ONLINE_SALE
#     ON USER_INFO.USER_ID = ONLINE_SALE.USER_ID
# WHERE USER_INFO.JOINED LIKE '2021%'
# # GROUP BY YEAR(ONLINE_SALE.SALES_DATE), MONTH(ONLINE_SALE.SALES_DATE)
# ORDER BY YEAR(ONLINE_SALE.SALES_DATE), MONTH(ONLINE_SALE.SALES_DATE);

# SELECT
#     COUNT(*)
# FROM
#     USER_INFO UI
#     JOIN ONLINE_SALE USING(USER_ID)
# WHERE
#     UI.JOINED LIKE '2021%';















# select
#     year(b.sales_date) YEAR,
#     month(b.sales_date) MONTH,
#     count(a.user_id),
#     round(
#         count(b.sales_amount) / 
#             (
#                 select count(user_id)
#                 from user_info
#                 where year(joined) = '2021'
#             )
#         , 1
#     )
    
# from user_info a
# join online_sale b
#     on a.user_id = b.user_id
# where year(a.joined) = '2021'
# group by year(b.sales_date), month(b.sales_date)
# order by year(b.sales_date), month(b.sales_date)
# ;